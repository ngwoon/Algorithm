#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> paint;
int dp[300001];
int maxFront[300001];
int n,s;

int main(void) {
    scanf("%d %d", &n, &s);

    paint.resize(n+1);
    for(int i=1; i<=n; ++i)
        scanf("%d %d", &paint[i].first, &paint[i].second);
    
    sort(paint.begin(), paint.end(), less<pair<int, int>>());

    for(int i=1; i<=n; ++i) {
        for(maxFront[i]=maxFront[i-1]+1; maxFront[i] < i; ++maxFront[i]) {
            if(paint[i].first - paint[maxFront[i]].first < s)
                break;
        }
        --maxFront[i];
    }

    for(int i=1; i<=n; ++i) {
        dp[i] = dp[maxFront[i]] + paint[i].second;
        dp[i] = max(dp[i], dp[i-1]);
    }

    printf("%d", dp[n]);
}