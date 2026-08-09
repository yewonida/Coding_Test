#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;    

vector<bool> solution(vector<string> string_list, vector<string> query_list) {
    vector<bool> answer;
    
    unordered_set<string> strSet(string_list.begin(), string_list.end());

    for(string query : query_list){

        if(strSet.find(query) != strSet.end()){
            answer.push_back(true);
        }else{
            answer.push_back(false);    
        }
    }
    

    return answer;
}

int main(){
    vector<string> string_list = {"apple", "banana","cherry", "date"};
    vector<string> query_list = {"apple", "cherry", "grape"};

    vector<bool> result = solution(string_list, query_list);

    for(bool res : result){
        cout << (res ? "true" : "false") << endl;
    }

    return 0;
}