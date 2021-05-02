#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int forest[500][500];
int ans, n;

void dfs(int y, int x, int before, int k) {
    bool moved = false;
    for(int i=0; i<4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int cur = forest[ny][nx];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(cur <= before)
            continue;
        
        moved = true;
        forest[ny][nx] = 0;
        dfs(ny, nx, cur, k+1);
        forest[ny][nx] = cur;
    }
    if(!moved)
        ans = ans < k ? k : ans;
}

int main(void) {
    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            scanf("%d", &forest[i][j]);
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            dfs(i,j,0,0);
    }

    printf("%d", ans);
}