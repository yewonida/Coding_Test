#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> phone_number;
    
    //일단 다 넣고 
    for(int i=0; i<phone_book.size(); i++){
        phone_number.insert(phone_book[i]);
    }
    
    //하나씩 짜르고 확인
    for(int i=0; i<phone_book.size(); i++){
        for(int j=0; j<phone_book[i].size(); j++){
             string frontLan = phone_book[i].substr(0,j);
            
            if(phone_number.find(frontLan) != phone_number.end()){
                answer = false;
                return answer;
            }
        }
       
    }
      
    return answer;
}