#include <iostream>
#include <vector>
using namespace std;
int main() {

	const long long MOD = 1'000'000'007;
	
	int N,M,K;
	cin >> N >> M >> K;
	vector<vector<long long>> dp(N+1, vector<long long>(M+1, 0));
	vector<vector<bool>> rest(N + 1, vector<bool>(M + 1, false));

	//출발지
	dp[1][1] = 1;

	//휴식 dp는 0으로 
	for(int i=0; i<K; i++){
		int n,m;
		cin >> n >> m;
		rest[n][m] = true;
	}
	

	
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			if (i == 1 && j == 1) {
            continue;
        }

			if(rest[i][j]){
				continue;
			}

			for(int dice=1;dice<=6;dice++){
				if(i-dice >=1){
					dp[i][j] =
                    (dp[i][j] + dp[i - dice][j]) % MOD;
				}
				if(j-dice >=1){
					 dp[i][j] =
                    (dp[i][j] + dp[i][j - dice]) % MOD;
				}
			}
			}
		}
		cout << dp[N][M];

	return 0;
	}



//그니깐 결국 dp[i][j] = dp[i-1][j] + dp[i][j-1] 가 아니라 
// 이 문제는 주사위 수가 뭐가 나올지 모르니깐 
// dp[i][j]
// = dp[i-1][j] + dp[i-2][j] + ... + dp[i-6][j]
// + dp[i][j-1] + dp[i][j-2] + ... + dp[i][j-6]