#include <bits/stdc++.h>
using namespace std;

int dp[10001];
vector<int> coins;
int n,k;

int main(void) {
    scanf("%d %d", &n, &k);

    coins.resize(n);
    for(int i=0; i<n; ++i) scanf(" %d", &coins[i]);

    dp[0] = 1;
    for(int i=0; i<n; ++i) {
        for(int j=coins[i]; j<=k; ++j) {
            dp[j] = dp[j] + dp[j-coins[i]];
        }
    }

    printf("%d", dp[k]);
}