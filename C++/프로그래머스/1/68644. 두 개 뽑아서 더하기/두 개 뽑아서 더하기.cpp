#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    int result;
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            result = numbers[i] + numbers[j];
            answer.push_back(result);
        }
    }
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    return answer;
}