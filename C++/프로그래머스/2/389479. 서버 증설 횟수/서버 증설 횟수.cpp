#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    //크기 24, 모두 0으로 초기화 
    vector<int> incrementServers(24,0);
    vector<int> incrementServersCount(24,0);
    vector<int> expireServers(24, 0);  // 이 시간에 "만료"되는 서버 수 누적
    
    for(int i=0; i<24; i++){
        int needServerCount = players[i] / m; //지금 시점에 필요한 서버 개수
        
        if(expireServers[i]>0){
                incrementServers[i] -= expireServers[i];
            }

        if(incrementServers[i] < needServerCount){
            int diff = needServerCount-incrementServers[i];
           incrementServers[i] += diff;
           incrementServersCount[i] = diff;
                for(int j=i+1; j<i+k && j<24; j++){
                    incrementServers[j]+= diff;
                }
        }
    }
    
    for(int i=0; i<24;i++){
        answer += incrementServersCount[i];
    }
    
    return answer;
}