#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> stk;

    answer.resize(prices.size(), 0);
    stk.push({0, 0});
    int len = prices.size();
    for(int i=0; i<len; ++i) {
        while(prices[i] < stk.top().first) {
            pair<int, int> top = stk.top();
            stk.pop();
            answer[top.second] = i - top.second;
        }
        stk.push({prices[i], i});
    }

    while(stk.size() != 1) {
        pair<int, int> top = stk.top();
        stk.pop();
        answer[top.second] = len - 1 - top.second;
    }
    
    return answer;
}