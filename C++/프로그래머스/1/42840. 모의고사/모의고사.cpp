#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> firstpattern = {1,2,3,4,5};
vector<int> secondpattern = {2,1,2,3,2,4,2,5};
vector<int> thirdpattern = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer; //가장 문제를 많이 맞힌 수포자
    
    vector<int> mathcorrect(3);
    for(int i=0; i< answers.size(); i++){
        if(answers[i] == firstpattern[i%firstpattern.size()]){
            mathcorrect[0]++;
            }
        if(answers[i] == secondpattern[i%secondpattern.size()]){
            mathcorrect[1]++;
            }
        if(answers[i] == thirdpattern[i%thirdpattern.size()]){
            mathcorrect[2]++;
        }
    }
    
    int maxScore = *max_element(mathcorrect.begin(),mathcorrect.end());
    for(int i=0; i<3; i++){
        if(mathcorrect[i] == maxScore){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}