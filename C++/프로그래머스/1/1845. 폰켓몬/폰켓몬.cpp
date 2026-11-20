#include <vector>
#include <unordered_set> 
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> numbers;
    for(int i=0; i< nums.size(); i++){
        numbers.insert(nums[i]);
    }
    
    if(nums.size() > numbers.size()*2 ){
        return numbers.size();
    }
    
    answer = nums.size() / 2;
    return answer;
    
}