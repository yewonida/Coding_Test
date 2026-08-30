#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> participantList;
    participantList[participant[0]] = 0;
    for(int i=1; i<participant.size();i++){
        
        //중복되는거 있으면 정수를 +
        if(participantList.find(participant[i])!= participantList.end()){
            participantList[participant[i]] ++;
            continue;
        }
        participantList[participant[i]] = 0;
    }
    
    for(int i=0; i<completion.size(); i++){
        if(participantList.find(completion[i])!= participantList.end()){
            if(participantList[completion[i]] == 0){
                participantList.erase(completion[i]);
            }else if(participantList[completion[i]] != 0){
                participantList[completion[i]]--;
            }
        }
    }
    
    for (const auto& [key, value] : participantList) {
        answer = key;
    }
        
    
    
    return answer;
}