#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

pair<int, int> walk[101];
pair<int, int> bike[101];
int dp[101][100000];
int n,k;

int solve(int city, int t) {
    if(t > k)
        return -INF;
    if(city == n)
        return 0;

    int& ret = dp[city][t];
    if(ret == -1)
        ret = max(solve(city+1, t+walk[city].first) + walk[city].second, solve(city+1, t+bike[city].first) + bike[city].second);
    return ret;
}

int main(void) {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; ++i)
        scanf("%d %d %d %d", &walk[i].first, &walk[i].second, &bike[i].first, &bike[i].second);

    memset(dp, -1, sizeof(dp));

    printf("%d", solve(0, 0));
}