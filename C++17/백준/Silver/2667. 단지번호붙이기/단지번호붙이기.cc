#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int dx[4] = {-1, 1, 0, 0};   
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, vector<string> &map, vector<vector<bool>> &visited){
    visited[x][y] = true;
    int count = 1;   

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;   
        if(visited[nx][ny]) continue;                          
        if(map[nx][ny] == '0') continue;                      

        count += dfs(nx, ny, map, visited);
    }
    return count;
}

int main(){
    cin >> N;

    vector<string> map(N);
    for(int i=0; i<N; i++){
        cin >> map[i];  
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<int> answer;   

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == '1' && !visited[i][j]){
                answer.push_back(dfs(i, j, map, visited));  
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << "\n";
    }

    return 0;
}