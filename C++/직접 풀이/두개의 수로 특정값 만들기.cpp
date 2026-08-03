#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool solution(vector<int> arr, int target) {
    unordered_set<int> numSet;

    for(int num : arr){
        int needNum = target-num;

        //중복 확인
        if(numSet.find(needNum)!= numSet.end()){
            return true;
        }    
        
        numSet.insert(num);
    }

    return false;
}

int main(){
    
    vector<int> arr = {1,2,3,5};
    int target = 9;

    if(solution(arr,target)){
        cout << "true";
    }else{
        cout << "false";
    }

    return 0;
}

