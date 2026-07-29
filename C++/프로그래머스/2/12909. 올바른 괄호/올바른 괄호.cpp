#include<string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> stringArr;
    bool check = true;
    
    for (int i=0; i<s.length(); i++){
        if(stringArr.empty()){
            stringArr.push(s[i]);
        }else if(stringArr.top() != s[i] && stringArr.top() =='(' ){
            stringArr.pop();
        }else{
            stringArr.push(s[i]);
        }
    }
    
    answer = stringArr.empty();

    return answer;
}