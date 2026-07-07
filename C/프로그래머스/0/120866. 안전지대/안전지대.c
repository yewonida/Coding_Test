#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols) {
    int answer = 0;
    int n = board_rows;
    
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