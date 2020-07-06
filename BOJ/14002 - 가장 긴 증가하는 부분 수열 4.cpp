#include <bits/stdc++.h>
using namespace std;

int dp[1000];
int seq[1000];
int trace[1000];
int n;

int solve(int start) {
    int& ret = dp[start];
    if(ret == 0) {
        for(int i=start + 1; i<n; ++i) {
            if(seq[i] > seq[start]) {
                int res = solve(i);
                if(ret < res + 1) {
                    ret = res + 1;
                    trace[start] = i;
                }
            }
        }
        if(ret == 0)
            ret = 1;
    }
    return ret;
}

int main(void) {
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &seq[i]);

    for(int i=0; i<n; ++i)
        trace[i] = -1;

    for(int i=0; i<n; ++i)
        solve(i);

    int maxVal = 0, sIndex;
    for(int i=0; i<n; ++i) {
        if(maxVal <= dp[i]) {
            maxVal = dp[i];
            sIndex = i;
        }
    }    

    printf("%d\n", maxVal);
    while(trace[sIndex] > 0) {
        printf("%d ", seq[sIndex]);
        sIndex = trace[sIndex];
    }
    printf("%d", seq[sIndex]);
}
