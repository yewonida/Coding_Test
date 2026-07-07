#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    
    for(int i =0; i<n; i++){
        for (int j=0; j<n; j++){
            if(board[i][j] == 1){
                //위
                if(i!=0){
                    if(board[i-1][j] !=1){
                        board[i-1][j] =2;
                    }
                }
                //아래
                if(i!=n-1){
                    if(board[i+1][j]!=1){
                        board[i+1][j] =2 ;
                    }
                    
                }
                //왼쪽
                if(j!=0){
                    if(board[i][j-1] !=1){
                        board[i][j-1]=2 ;
                    }
                     
                }
                //오른쪽
                if(j!=n-1){
                    if(board[i][j+1] !=1){
                        if(board[i][j+1]!=1){
                             board[i][j+1] =2 ;
                        }
                       
                    }
                    
                }
                //위+왼쪽
                if(i!=0 && j!=0){
                    if(board[i-1][j-1] != 1){
                        board[i-1][j-1] =2 ;
                    }
                }
                //위+오른쪽
                if(i!=0 && j!=n-1){
                    if(board[i-1][j+1]!=1){
                        board[i-1][j+1] = 2 ;
                    }
                    
                }
                //아래+왼쪽
                if(i!=n-1 && j!=0){
                    if(board[i+1][j-1]!=1){
                        board[i+1][j-1] =2 ;
                    }
                    
                }
                //아래+오른쪽
                if(i!=n-1 && j!=n-1){
                    if(board[i+1][j+1]!=1){
                        board[i+1][j+1] =2 ;
                    }
                    
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 0){
                answer++;
            }
        }
        
    }
    return answer;
}