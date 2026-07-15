#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    
    vector<int> answer;

    for (int currentNum : arr) {
        if (answer.empty() || answer.back() != currentNum) {
            answer.push_back(currentNum);
        }
    }

    return answer;
}