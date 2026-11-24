#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;   // (원래 위치, 우선순위)
    
    for(int i=0; i<priorities.size(); i++){
        q.push({i,priorities[i]});
    }
    
    
    while(true){
        bool check = false;
        // 1. 큐에 남은 것 중 최댓값 구하기
        queue<pair<int, int>> temp = q;
        int maxP = 0;
        while (!temp.empty()) {
            maxP = max(maxP, temp.front().second);
            temp.pop();
        }

        // 2. 맨 앞이 최댓값보다 작으면 뒤로 보내기
        if (q.front().second < maxP) {
            auto front = q.front();
            q.pop();
            q.push(front);   // pair 그대로 다시 넣으면 됨
            check = true;
        }
        if(!check){
            auto pop_number = q.front();
            q.pop();
            answer ++;
            if(pop_number.first == location){
                return answer;
            }
        }
    }
    return answer;
}