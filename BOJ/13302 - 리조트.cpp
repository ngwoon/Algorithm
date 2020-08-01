#include <bits/stdc++.h>
using namespace std;

vector<int> busy;
int dp[101][101];
int n,m;

int solve(int day, int cost, int coupon) {
    if(day >= n+1)
        return cost;
    if(busy[day])
        return solve(day+1, cost, coupon);

    int& ret = dp[day][coupon];
    if(ret == -1) {
        int ans = (1<<30)-1;
        ans = min(ans, solve(day+1, cost+10000, coupon));
        ans = min(ans, solve(day+3, cost+25000, coupon+1));
        ans = min(ans, solve(day+5, cost+37000, coupon+2));

        if(coupon >= 3)
            ans = min(ans, solve(day+1, cost, coupon-3));

        ret = ans - cost;
        return ans;
    }
    else
        return ret + cost;
}

int main(void) {
    scanf("%d %d", &n, &m);

    busy.resize(n+1, 0);
    for(int i=0; i<m; ++i) {
        int bday;
        scanf("%d", &bday);
        busy[bday] = 1;
    }

    for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)
            dp[i][j] = -1;
    printf("%d", solve(1, 0, 0));
}