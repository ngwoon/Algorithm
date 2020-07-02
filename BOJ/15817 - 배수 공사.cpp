#include <bits/stdc++.h>
using namespace std;

int dp[100][10001];
vector<pair<int, int>> pipe;
int N, x;
int ans=0;

int solve(int index, int len) {
    int& cur = dp[index][len];
    if(cur != -1) return cur;

    cur = 0;
    int repeat = pipe[index].second;
    for(int i=0; i<repeat; ++i) {
        cur = max(cur, solve(i, len - pipe[index].first * (repeat-i)))
    }
}

int main(void) {
    scanf("%d %d", &N, &x);

    pipe.resize(N);
    for(int i=0; i<N; ++i)
        scanf(" %d %d", &pipe[i].first, &pipe[i].second);

    memset(dp, -1, sizeof(dp));
    
    int sum=0;
    for(int i=0; i<N; ++i) sum += solve(i, x);
    
    printf("%d",ans);
}