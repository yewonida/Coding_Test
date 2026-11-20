#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int N,M;
    cin >> N>>M;
    
    vector<string> name(N+M);
    for(int i=0; i<N+M; i++){
        cin >> name[i];
    }  

    unordered_map<string,int> people;

    for(auto n : name){
        people[n] += 1;
    }

    vector<string> answer;

    for (const auto& [key,value] :people) {
	    if(value >=2){
            answer.push_back(key);
        }
    }

    sort(answer.begin(), answer.end());  // 사전순 정렬

    cout << answer.size() << "\n";
    
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << "\n";
    }
    


}