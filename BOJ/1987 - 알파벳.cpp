#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> visited;
int ans,r,c;
char field[20][20];

void dfs(int y, int x, int cnt) {
    if(cnt > ans)
        ans = cnt;
    
    for(int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;
        
        if(visited[field[ny][nx]-'A'] != 0)
            continue;

        visited[field[ny][nx]-'A'] += 1;
        dfs(ny, nx, cnt+1);
        visited[field[ny][nx]-'A'] -= 1;
    }
}

int main(void) {
    scanf("%d %d", &r, &c);

    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j)
            scanf(" %c", &field[i][j]);
    }

    visited.resize(26, 0);

    visited[field[0][0]-'A'] += 1;
    dfs(0,0,1);

    printf("%d", ans);
}