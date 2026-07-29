#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    stack<string> cards1Stack;
    stack<string> cards2Stack;
    
    for(int i = cards1.size()-1;i>=0;i-- ){
        cards1Stack.push(cards1[i]);
    }
    for(int i = cards2.size()-1;i>=0;i-- ){
        cards2Stack.push(cards2[i]);
    }

    for(int i =0; i<goal.size();i++){
        if(!cards1Stack.empty() && goal[i] == cards1Stack.top()){
            cards1Stack.pop();
        }else if( !cards2Stack.empty() && goal[i] == cards2Stack.top() ){
            cards2Stack.pop();
        }else{
            answer = "No";
            break;
        }
    }
    
    return answer;
}