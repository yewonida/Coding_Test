#include <iostream>
#include <vector>

using namespace std;

void dfs (int node, vector<bool> &visited, vector<vector<int>> &graph){
    visited[node] = true;
    for(int i=0; i<graph[node].size(); i++){
         int next = graph[node][i];
         if(!visited[next]){
            dfs(next,visited,graph);
        }
    }
}

using namespace std;
int main(){
    int N;
    int M;
    cin >> N>>M;

    vector<pair<int,int>> input(M+1);

    //그래프 만들기
    vector<vector<int>> graph(N+1);
    for(int i=1; i<=M; i++){
        cin >> input[i].first >> input[i].second;
        graph[input[i].first].push_back(input[i].second);
        graph[input[i].second].push_back(input[i].first);
    }

    int answer =0; 
    bool check = true;
    vector<bool> visited(N+1,false);
    while(check){
        int next =-1; 

        for(int i= 1; i<visited.size(); i++){
            if(!visited[i]){
                next = i;
                break;
            }
        }
        if(next == -1) break;                // 미방문 정점이 없으면 바로 종료

        dfs(next,visited,graph);
        answer++;
        
    }

    cout<< answer;
    return 0;


}