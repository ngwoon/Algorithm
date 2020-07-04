#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> seq;
int dp[101];

int solve(int start) {
    int& ret = dp[start];
    if(ret == 0) {
        for(int i=start+1; i<n; ++i) {
            if(seq[i].second > seq[start].second) {
                ret = max(ret, solve(i) + 1);
            }
        }
        if(ret == 0)
            ret = 1;
    }
    return ret;
}

int main(void) {
    scanf("%d", &n);

    seq.resize(n, {0,0});
    for(int i=0; i<n; ++i)
        scanf("%d %d", &seq[i].first, &seq[i].second);
    
    sort(seq.begin(), seq.end());
    dp[n-1] = 1;

    for(int i=0; i<n; ++i)
        solve(i);

    int maxVal = 0;
    for(int i=0; i<n; ++i) {
        if(maxVal < dp[i]) maxVal = dp[i];
    }

    printf("%d", n - maxVal);
}