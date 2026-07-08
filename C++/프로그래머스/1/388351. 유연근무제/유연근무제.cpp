#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    vector<int> acceptSchedules(schedules.size());
    vector<bool>check(timelogs.size(),true);
    
    //출석 인정 시각 배열
    for(int i =0; i<schedules.size(); i++){
        if(schedules[i] % 100 >= 50){
            int hour = schedules[i] / 100;
            int minute = schedules[i] % 10;
            acceptSchedules[i] = (hour+1)*100 + minute;
            continue;
        }
        acceptSchedules[i] = schedules[i] +10;
    }
    
    
    
    
    for(int i=0; i<timelogs.size(); i++){
        for(int j=0; j<7; j++){
            if(startday == 6){
                startday ++;
                continue;
            }
            else if(startday == 7){
                startday = 1;
                continue;
            }
            
            if(acceptSchedules[i]<timelogs[i][j]){
                check[i] = false;
                startday ++;
                continue;
            }
            startday ++;
        }
    }
    
    for(int i =0; i<timelogs.size(); i++){
        if(check[i]){
            answer++;
        }
    }
    return answer;
}