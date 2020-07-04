#include <bits/stdc++.h>
using namespace std;

/*
    
*/

int dp[1001];
int seq[1001];
int n;

int solve(int start) {
    int& ret = dp[start];
    if(ret == 0) {
        for(int i=start + 1; i<=n; ++i) {
            if(seq[i] > seq[start])
                ret = max(ret, solve(i) + 1);
        }
        if(ret == 0)
            ret = 1;
    }
    return ret;
}

int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &seq[i]);

    dp[n] = 1;
    for(int i=1; i<=n; ++i)
        solve(i);

    int maxVal = 0;
    for(int i=1; i<=n; ++i) {
        if(maxVal < dp[i])
            maxVal = dp[i];
    }
    printf("%d", maxVal);
}