#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];
vector<int> lc, rc;
int n;

int solve(int l, int r) {
    if(l == n || r == n)
        return 0;

    int& ret = dp[l][r];
    if(ret == -1) {
        if(lc[l] <= rc[r])
            ret = max(ret, max(solve(l+1,r), solve(l+1,r+1)));
        else
            ret = solve(l, r+1) + rc[r];
    }
    return ret;
}

int main(void) {
    scanf("%d", &n);

    int c;
    for(int i=0; i<n; ++i) {
        scanf("%d", &c);
        lc.push_back(c);
    }
    for(int i=0; i<n; ++i) {
        scanf("%d", &c);
        rc.push_back(c);
    }

    memset(dp, -1, sizeof(dp));
    solve(0,0);

    printf("%d", dp[0][0]);
}