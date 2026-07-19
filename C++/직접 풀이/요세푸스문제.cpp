#include <iostream>
#include <queue>

using namespace std;


int solutuion(int N,int K){

    queue<int> queueArr;
    for(int i =0; i<N; i++){
        queueArr.push(i+1);
    }

    while(queueArr.size() > 1){
        //K-1번째 요소들을 뒤로 보내고 
        for(int i=0; i<K-1;i++){
            queueArr.push(queueArr.front());
            queueArr.pop();
        }
        // 그러면 가장 앞에온 K번째 요소를 삭제
        queueArr.pop();
    }
    return queueArr.front();
}

int main(){
    cout<<solutuion(6,2);
    return 0;
}