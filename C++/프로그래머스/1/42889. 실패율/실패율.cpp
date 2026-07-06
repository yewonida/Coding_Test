#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// pair 기준으로 비교하도록 수정
bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first)
        return a.second < b.second; // 스테이지 번호 작은게 먼저
    return a.first > b.first;       // 실패율 큰게 먼저
}

vector<int> solution(int N, vector<int> stages) {
    int stageSize = stages.size();
    vector<double> fault(N, 0);   // 크기 할당
    vector<int> answer;
    
    int k = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] == i + 1) { 
                k++;
            }
        }
        if (stageSize != 0)
            fault[i] = (double)k / stageSize;
        else
            fault[i] = 0;

        stageSize -= k;
        k = 0;
    }
    

    vector<pair<double, int>> final_fault;
    for (int i = 0; i < N; i++) {
        final_fault.push_back({fault[i], i + 1});
    }

    sort(final_fault.begin(), final_fault.end(), compare);

    // answer 채워주기 (안 하면 경고/문제될 수 있음)
    for (int i = 0; i < N; i++) {
        answer.push_back(final_fault[i].second);
    }

    return answer;
}