#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; 
    priority_queue<int> pq; //얘는 최대값을 알려주는 그런... 
    
    for(int i=0; i<priorities.size(); i++){
        q.push({i,priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        
        if(front.second < pq.top()){
            q.push(front);
        }
        else{
            pq.pop();
            answer ++;
            if(front.first == location){
                return answer;
            }
        }
    }
    
    
    
    return answer;
}