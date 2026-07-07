#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_value(int row,int column, const vector<vector<int>>& arr){
    
    int max_value =0;
    for(int i=0; i< arr[0].size(); i++){
        if(i!=column){
            if(arr[row-1][i] > max_value){
                max_value = arr[row-1][i];
            }
        }
    }
    
    return max_value;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    int k = land.size(); // 행 -> 3
    int c = land[0].size(); //열 -> 4
    vector<vector<int>> dp(k, vector<int>(c, 0));
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    
    for(int i=1; i<k; i++){
        for(int j=0; j<c; j++){
            dp[i][j] = max_value(i,j,dp) + land[i][j];
        }
    }

    answer = *max_element(dp[k-1].begin(),dp[k-1].end());

    return answer;
}