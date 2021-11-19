#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int forest[500][500];
int dp[500][500];
int n;

int dfs(int y, int x) {
    if(dp[y][x] == 0) {
        dp[y][x] = 1;
        bool moved = false;
        for(int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int cur = forest[ny][nx];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(cur <= forest[y][x])
                continue;

            dp[y][x] = max(dp[y][x], 1 + dfs(ny, nx));
        }
    }
    return dp[y][x];
}

int main(void) {
    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            scanf("%d", &forest[i][j]);
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            dfs(i,j);
        }
    }

    int ans=0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            ans = ans < dp[i][j] ? dp[i][j] : ans;
        }
    }

    printf("%d", ans);
}