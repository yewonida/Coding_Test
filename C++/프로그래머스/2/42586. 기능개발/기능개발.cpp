#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count;
    // 우선 언제 100이 넘는지 표시 
    vector<int> successDate(progresses.size(), 0);
    queue<int> checkDate;
    
    for(int i=0; i<progresses.size();i++){
        while(progresses[i] < 100){
            successDate[i] ++;
            progresses[i] += speeds[i];
        }
        
    }
    
    for(int i=0; i<successDate.size(); i++){
        checkDate.push(successDate[i]);
        cout<<successDate[i];
        
    }
    
    
    // 무조건 첫번째 일수 이상 부터 배포 가능
    while(!checkDate.empty()){
        count = 0;
        int k = checkDate.front(); //가장 앞자리 
        
        while(!checkDate.empty() && checkDate.front() <= k){
            checkDate.pop();
            count++;
            cout<<count;
        }
        answer.push_back(count);
        
    }
    
    return answer;
}