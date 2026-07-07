#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> arr(n+1);
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2; i< n+1; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 1234567; //int가 감당하지 못하기 때문에 바로 나누기를 해줘야 함
    }
    
   answer = arr[n];
    return answer ;
}