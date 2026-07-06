#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<char> st2; // 올바른 문자열인지 확인하는 스택

// 문자열 회전하기
// k : 문자열 회전 수
stack<char> change(string s, int k) {
    stack<char> st1; // 회전한 문자열을 넣어두는 스택

    // 회전하고 가장 앞에부터 push
    for (int i = k; i < (int)s.length(); i++) {
        st1.push(s[i]);
    }

    // 회전으로 뒤에 간 애들 push
    for (int j = 0; j < k; j++) {
        st1.push(s[j]);
    }

    return st1;
}

bool correct(stack<char> st_a, stack<char> st_b) {
    char c;
    bool check = true;

    while (check && !st_a.empty()) {
        c = st_a.top();
        st_a.pop();

        if (st_b.empty()) {
            if (c == '}' || c == ']' || c == ')') {
                st_b.push(c);
            } else {
                check = false;
                return check;
            }
        } else if (st_b.top() == '}' || st_b.top() == ']' || st_b.top() == ')') {
            if (c == '}' || c == ']' || c == ')') {
                st_b.push(c);
            } else {
                if (c == '[') {
                    if (!(st_b.top() == ']')) {
                        check = false;
                        return check;
                    }
                    else if(st_b.top() == ']'){
                        st_b.pop();
                    }
                }
                if (c == '{') {
                    if (!(st_b.top() == '}')) {
                        check = false;
                        return check;
                    }
                    else if(st_b.top() == '}'){
                        st_b.pop();
                    }
                }
                if (c == '(') {
                    if (!(st_b.top() == ')')) {
                        check = false;
                        return check;
                    }
                    else if(st_b.top() == ')'){
                        st_b.pop();
                    }
                }
            }
        }
    }
    
    if(!st_b.empty()){
        check = false;
    }
    
    

    return check;
}

int solution(string s) {
    int answer = 0;

    stack<char> st3;
    stack<char> st4; // 넣는 스택

    bool final_check = false;

    for (int i = 0; i < (int)s.length(); i++) {
        st3 = change(s, i);
        final_check = correct(st3, st4);

        if (final_check == true) {
            answer++;
        }
    }

    return answer;
}