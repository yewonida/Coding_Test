#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st1; //확인하는 스택
    
    for (char c : s) {
    
        if(st1.empty() || c!=st1.top()){
            st1.push(c);
        }
        else{
            st1.pop();
        }
    }   
    
    if(st1.empty()){
        answer=1;
    }
    
    return answer;
}