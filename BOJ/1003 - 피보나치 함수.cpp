#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> dp[41];
vector<int> src;

int main(void) {
    int t;
    scanf("%d", &t);
    src.resize(t);
    int maxN = 0;
    for(int i=0; i<t; ++i) {
        scanf(" %d", &src[i]);
        if(maxN < src[i]) maxN = src[i];
    }

    dp[0] = {1,0};
    dp[1] = {0,1};
    for(int i=2; i<=maxN; ++i)
        dp[i] = {dp[i-1].first + dp[i-2].first, dp[i-1].second + dp[i-2].second};

    for(int i=0; i<src.size(); ++i)
        printf("%lld %lld\n", dp[src[i]].first, dp[src[i]].second);
}