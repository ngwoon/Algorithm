#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> que;
    for(int i=0; i<progresses.size(); ++i)
        que.push_back(progresses[i]);
    
    int idx = 0;
    int daysSum = 0;
    while(idx < progresses.size()) {
        int rest = 100 - que[idx];
        int curDays = rest % speeds[idx] != 0 ? rest / speeds[idx] + 1 : rest / speeds[idx];
        daysSum += curDays;
        
        ++idx;
        int deploy = 1;
        while(idx < progresses.size()) {
            if(que[idx] + speeds[idx] * daysSum >= 100) {
                ++deploy;
                ++idx;
            } else {
                que[idx] += speeds[idx] * daysSum;
                break;
            }
        }
        answer.push_back(deploy);
    }

    return answer;
}