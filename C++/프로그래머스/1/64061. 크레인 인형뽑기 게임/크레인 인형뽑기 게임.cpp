#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int k;
    
    stack<int> st; //크레인으로 옮긴 인형 담는 스택
    for(int i =0; i< moves.size(); i++){
        k = moves[i]-1; //moves로 들어오고 있는건 열의 순서! 인덱스가 아님
        for(int j =0; j< board.size(); j++){
            if(board[j][k] !=0){
                if(!st.empty() && board[j][k]  == st.top()){
                    st.pop();
                    answer += 2;
                }
                else{
                    st.push(board[j][k]);
                }
                board[j][k] = 0;
                break;
            }
        }
        
    }
    
    
    return answer;
}