#!/usr/bin/env python3
"""저장소의 풀이 폴더를 훑어 README.md의 자동 생성 구역을 다시 만든다.

README.md 안의 아래 표시 사이만 덮어쓴다. 그 밖의 내용은 그대로 둔다.
  <!-- AUTO:BADGES:START --> ... <!-- AUTO:BADGES:END -->
  <!-- AUTO:LIST:START -->   ... <!-- AUTO:LIST:END -->
"""
import os
import re
import sys
import unicodedata
import urllib.parse

ROOT = os.path.abspath(sys.argv[1] if len(sys.argv) > 1 else ".")
README = os.path.join(ROOT, "README.md")

LANG = {
    ".cpp": "C++", ".cc": "C++", ".c": "C", ".py": "Python", ".java": "Java",
    ".js": "JavaScript", ".ts": "TypeScript", ".kt": "Kotlin", ".swift": "Swift",
    ".go": "Go", ".rs": "Rust", ".cs": "C#", ".rb": "Ruby", ".sql": "SQL",
}
TIERS = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby"]
ROMAN = {"V": 5, "IV": 4, "III": 3, "II": 2, "I": 1}
SELF_DIR = "직접 풀이"


def nfc(s):
    return unicodedata.normalize("NFC", s)


def link(path):
    rel = os.path.relpath(path, ROOT).replace(os.sep, "/")
    return "./" + urllib.parse.quote(rel)


def langs_in(dirpath):
    found = []
    for f in sorted(os.listdir(dirpath)):
        lang = LANG.get(os.path.splitext(f)[1].lower())
        if lang and lang not in found:
            found.append(lang)
    return found


def collect():
    problems, self_solved = [], []
    for dirpath, dirnames, filenames in os.walk(ROOT):
        dirnames[:] = sorted(d for d in dirnames if not d.startswith(".") and not d.endswith(".dSYM"))
        if dirpath == ROOT:
            continue

        if nfc(os.path.basename(dirpath)) == SELF_DIR:
            for f in sorted(filenames):
                name, ext = os.path.splitext(f)
                if ext.lower() in LANG:
                    self_solved.append((nfc(name), LANG[ext.lower()], link(os.path.join(dirpath, f))))
            continue

        if "README.md" not in filenames:
            continue
        with open(os.path.join(dirpath, "README.md"), encoding="utf-8") as fp:
            text = nfc(fp.read())
        head = re.match(r"#\s*\[(.+?)\]\s*(.+?)\s*-\s*(\d+)\s*$", text.splitlines()[0] if text else "")
        url = re.search(r"\[문제 링크\]\((.+?)\)", text)
        if not head or not url:
            continue
        site = "백준" if "acmicpc" in url.group(1) else "프로그래머스"
        langs = langs_in(dirpath) or ["코드"]
        problems.append({
            "site": site, "level": head.group(1).strip(), "title": head.group(2).strip(),
            "num": int(head.group(3)), "url": url.group(1), "langs": langs, "path": link(dirpath),
        })
    return problems, self_solved


def level_key(p):
    if p["site"] == "프로그래머스":
        m = re.search(r"(\d+)", p["level"])
        return (int(m.group(1)) if m else 99, 0)
    parts = p["level"].split()
    tier = TIERS.index(parts[0]) if parts and parts[0] in TIERS else 99
    return (tier, -ROMAN.get(parts[1], 0) if len(parts) > 1 else 0)


def level_label(p):
    if p["site"] == "프로그래머스":
        return p["level"].replace("level ", "Lv. ")
    return p["level"]


def level_group(p):
    return level_label(p) if p["site"] == "프로그래머스" else p["level"].split()[0]


def badges(problems, self_solved):
    n = {s: sum(p["site"] == s for p in problems) for s in ("프로그래머스", "백준")}
    langs = []
    for p in problems:
        for l in p["langs"]:
            if l in LANG.values() and l not in langs:
                langs.append(l)
    for _, l, _ in self_solved:
        if l not in langs:
            langs.append(l)
    logo = {"C++": "cplusplus", "Python": "python", "Java": "openjdk", "JavaScript": "javascript"}
    lines = []
    for l in langs:
        label = urllib.parse.quote(l.replace("-", "--"))
        extra = f"&logo={logo[l]}&logoColor=white" if l in logo else ""
        lines.append(f"![{l}](https://img.shields.io/badge/{label}-00599C?style=flat-square{extra})")
    lines.append(f"![Programmers](https://img.shields.io/badge/Programmers-{n['프로그래머스']}_solved-1E90FF?style=flat-square)")
    lines.append(f"![Baekjoon](https://img.shields.io/badge/Baekjoon-{n['백준']}_solved-F7B500?style=flat-square)")
    lines.append("![Auto push](https://img.shields.io/badge/auto_push-BaekjoonHub-2ea44f?style=flat-square)")
    return "\n".join(lines)


def listing(problems, self_solved):
    out = ["## 📊 풀이 현황", "", "| 플랫폼 | 세부 | 합계 |", "|:---:|:---|:---:|"]
    for site in ("프로그래머스", "백준"):
        ps = sorted((p for p in problems if p["site"] == site), key=level_key)
        groups = []
        for p in ps:
            g = level_group(p)
            if groups and groups[-1][0] == g:
                groups[-1][1] += 1
            else:
                groups.append([g, 1])
        detail = " · ".join(f"{g} ({c})" for g, c in groups) or "-"
        out.append(f"| {site} | {detail} | **{len(ps)}** |")
    out.append(f"| 직접 풀이 | - | **{len(self_solved)}** |")
    out += ["", "## 📝 문제 목록", ""]

    for site, icon in (("프로그래머스", "🟦"), ("백준", "🟨")):
        ps = sorted((p for p in problems if p["site"] == site), key=lambda p: (level_key(p), p["num"]))
        if not ps:
            continue
        out += ["<details>", f"<summary><b>{icon} {site} ({len(ps)}문제)</b></summary>", "",
                "| 난이도 | 번호 | 문제 | 풀이 |", "|:---:|:---:|:---|:---:|"]
        for p in ps:
            out.append(f"| {level_label(p)} | {p['num']} | [{p['title']}]({p['url']}) | "
                       f"[{' · '.join(p['langs'])}]({p['path']}) |")
        out += ["", "</details>", ""]

    if self_solved:
        out += ["<details>", f"<summary><b>✏️ 직접 풀이 ({len(self_solved)}문제)</b></summary>", "",
                "| 문제 | 풀이 |", "|:---|:---:|"]
        for name, lang, path in self_solved:
            out.append(f"| {name} | [{lang}]({path}) |")
        out += ["", "</details>", ""]
    return "\n".join(out).rstrip()


def replace(text, key, body):
    pattern = re.compile(rf"(<!-- AUTO:{key}:START -->\n).*?(\n<!-- AUTO:{key}:END -->)", re.S)
    if not pattern.search(text):
        sys.exit(f"README.md에 AUTO:{key} 표시가 없습니다.")
    return pattern.sub(lambda m: m.group(1) + body + m.group(2), text)


def main():
    problems, self_solved = collect()
    with open(README, encoding="utf-8") as fp:
        text = fp.read()
    new = replace(text, "BADGES", badges(problems, self_solved))
    new = replace(new, "LIST", listing(problems, self_solved))
    if new != text:
        with open(README, "w", encoding="utf-8") as fp:
            fp.write(new)
        print("README.md 갱신됨")
    else:
        print("변경 없음")


if __name__ == "__main__":
    main()
