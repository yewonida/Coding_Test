#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> computer_graph, vector<bool> &visited, int computer){
        visited[computer] = true;
        for(int i=0; i<computer_graph[computer].size(); i++){
            int next_computer = computer_graph[computer][i];
            if(!visited[next_computer]){
                dfs(computer_graph, visited, next_computer);
            }
        }
    }

int main(){
    int computer_count =0;
    int computer_pair_count=0;
    cin >> computer_count;
    cin >> computer_pair_count;

    int answer=0;

    vector<pair<int,int>> computer_pairs(computer_pair_count);
    for(int i=0; i<computer_pair_count; i++){
        cin >> computer_pairs[i].first >> computer_pairs[i].second;
    }

    vector<vector<int>> computer_graph(computer_count + 1);
    for(int i=0; i<computer_pair_count; i++){
        // 양방향 그래프 생성
        computer_graph[computer_pairs[i].first].push_back(computer_pairs[i].second);
        computer_graph[computer_pairs[i].second].push_back(computer_pairs[i].first);
    }

    // 그냥 배열에는 크기에 변수가 들어가면 안됨!
    vector<bool> visited(computer_count+1, false); 

    

    dfs(computer_graph, visited, 1);
    for(int i=1; i<computer_count+1; i++){
        if(visited[i]){
            answer++;
        }
    }


    cout << answer-1; // 0번 컴퓨터 제외

    return 0;


}