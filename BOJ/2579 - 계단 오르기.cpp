#include <bits/stdc++.h>
using namespace std;

int dp[301];
vector<int> scores;

int main(void) {
    int n;
    scanf("%d", &n);

    scores.resize(n);
    for(int i=0; i<n; ++i) scanf(" %d", &scores[i]);

    dp[0] = scores[0];
    dp[1] = scores[0] + scores[1];
    dp[2] = max(scores[0] + scores[2], scores[1] + scores[2]);

    for(int i=3; i<n; ++i)
        dp[i] = max(dp[i-2], dp[i-3] + scores[i-1]) + scores[i];

    printf("%d", dp[n-1]);
}