#include <bits/stdc++.h>
using namespace std;

vector<int> longest;
vector<int> trace;
int seq[1000001];
int n;

int main(void) {
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &seq[i]);

    longest.push_back(-1000000001);
    for(int i=0; i<n; ++i) {
        if(longest.back() < seq[i]) {
            longest.push_back(seq[i]);
            trace.push_back(longest.size()-2);
        }
        else if(longest.back() > seq[i]) {
            vector<int>::iterator iter = lower_bound(longest.begin(), longest.end(), seq[i]);
            *iter = seq[i];
            trace.push_back(iter-longest.begin()-1);
        }
        else
            trace.push_back(-1);
    }

    int order = -1, idx;
    for(int i=0; i<trace.size(); ++i) {
        if(order < trace[i]) {
            order = trace[i];
            idx = i;
        }
    }

    stack<int> stk;
    for(int i=idx; order >= 0 && i>=0; --i) {
        if(order == trace[i]) {
            stk.push(seq[i]);
            --order;
        }
    }
    
    printf("%d\n", longest.size() - 1);
    while(!stk.empty()) {
        printf("%d ", stk.top());
        stk.pop();
    }
}