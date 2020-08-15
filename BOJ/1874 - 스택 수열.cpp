#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
stack<int> stk;
string ans;

int main(void) {
    int n;
    scanf("%d", &n);

    nums.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &nums[i]);
    
    int seq = 1;
    int idx = 0;
    while(seq <= n) {
        if(!stk.empty() && stk.top() == nums[idx]) {
            stk.pop(); ans.append("-\n"); ++idx;
        } else {
            stk.push(seq++); ans.append("+\n");
        }
    }
    while(!stk.empty()) {
        if(stk.top() == nums[idx]) {
            ans.append("-\n");
            stk.pop(); ++idx;
        } else {
            ans.clear();
            ans.append("NO");
            break;
        }
    } 
    printf("%s", ans.c_str());
 }