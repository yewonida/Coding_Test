#include <string>
#include <algorithm>

using namespace std;

int solve(long long storey){

    if (storey == 0) return 0;
    
    int d = storey % 10; 
    
    if (storey < 10) {
        // 한 자리 수: 내려가기(d번) vs 10 채워서 -10 한 번(1번) 비교
        // 여기서 +1은 (10-d)에서 나온 10을 한번 눌렀다는
        return min(d, (10 - d) + 1);
    }
    
    long long down = storey / 10;
    long long up = storey / 10 + 1;
    
    int costDown = d + solve(down);
    int costUp = (10-d) + solve(up);
    
    return min(costDown, costUp);
    

}

int solution(int storey) {
    int answer = 0;
    answer = solve(storey);
    return answer;
}