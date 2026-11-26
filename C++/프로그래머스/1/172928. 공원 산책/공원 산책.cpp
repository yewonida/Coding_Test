#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2);
    // x = 줄(위아래), y = 칸(좌우)
    // N - 0, S - 1, E - 2, W - 3
    int dx[4] = {-1, 1, 0, 0};   // N: 위로 한 줄(-1), S: 아래로 한 줄(+1)
    int dy[4] = {0, 0, 1, -1};   // E: 오른쪽 한 칸(+1), W: 왼쪽 한 칸(-1)

    int H = park.size();      // 세로 (줄 수)
    int W = park[0].size();   // 가로 (칸 수)

    // 시작 위치 'S' 찾기
    int x = 0;
    int y = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (park[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        int n = routes[i][2] - '0';   

        int nx = x; //임시 좌표                  
        int ny = y;
        bool ok = true;               

        if (routes[i][0] == 'N') {
            for (int j = 0; j < n; j++) {
                nx += dx[0];
                ny += dy[0];
                // 지도 밖이거나 장애물 → 실패 (범위 검사 먼저!)
                if (nx < 0 || ny < 0 || nx >= H || ny >= W || park[nx][ny] == 'X') {
                    ok = false;
                    break;
                }
            }
        }
        if (routes[i][0] == 'S') {
            for (int j = 0; j < n; j++) {
                nx += dx[1];
                ny += dy[1];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W || park[nx][ny] == 'X') {
                    ok = false;
                    break;
                }
            }
        }
        if (routes[i][0] == 'E') {
            for (int j = 0; j < n; j++) {
                nx += dx[2];
                ny += dy[2];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W || park[nx][ny] == 'X') {
                    ok = false;
                    break;
                }
            }
        }
        if (routes[i][0] == 'W') {
            for (int j = 0; j < n; j++) {
                nx += dx[3];
                ny += dy[3];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W || park[nx][ny] == 'X') {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            x = nx;
            y = ny;
        }
    }

    answer[0] = x;
    answer[1] = y;
    return answer;
}