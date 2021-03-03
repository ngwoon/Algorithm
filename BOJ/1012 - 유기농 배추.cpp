#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int m,n;

void bfs(int sy, int sx, vector<vector<bool>>& field, vector<vector<bool>>& visited) {
    queue<pair<int, int>> que;
    visited[sy][sx] = true;
    que.push({sy, sx});

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if(!field[ny][nx])
                continue;
            if(visited[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            que.push({ny, nx});
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);

    while(t--) {
        int k;
        scanf(" %d %d %d", &m, &n, &k);
    
        vector<vector<bool>> field(n);
        for(int i=0; i<n; ++i)
            field[i].resize(m, false);

        vector<vector<bool>> visited(n);
        for(int i=0; i<n; ++i)
            visited[i].resize(m, false);

        for(int i=0; i<k; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            field[y][x] = true;
        }

        int ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(!visited[i][j] && field[i][j]) {
                    bfs(i, j, field, visited);
                    ++ans;
                }
            }
        }

        printf("%d\n", ans);
    }
}