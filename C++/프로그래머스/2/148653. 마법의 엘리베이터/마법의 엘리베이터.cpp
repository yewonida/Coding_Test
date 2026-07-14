#include <string>
using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int d = storey % 10;      // 현재 최하위 자리 값

        if (d < 5) {
            answer += d;           // 그대로 내려가는 게 이득
            storey /= 10;           // 이 자리는 처리 끝, 다음(윗) 자리로
        } else if(d>5) {
            answer += (10 - d);    // 올려서(10 채워서) 넘기는 게 이득
            storey = storey / 10 + 1;  // 윗자리에 올림(+1) 반영
        }
        //d가 5일 때
        else {
            // d == 5: 윗자리가 5 이상이면 올리는 쪽이 유리, 아니면 내려가는 쪽이 유리
            int upper = (storey / 10) % 10;
            if (upper >= 5) {
                answer += 5;
                storey = storey / 10 + 1;
            } else {
                answer += 5;
                storey /= 10;
            }
        }
    }

    return answer;
}