#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int n,m;
long long ans=0;

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) { 
            char c;
            scanf(" %c", &c);
            if(c == '1') {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                if(ans < dp[i][j]) ans = dp[i][j];
            }
        }
    }
    printf("%lld", ans*ans);
}