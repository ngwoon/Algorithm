#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

queue<pair<int, int>> que;
char paint[100][100];
vector<vector<bool>> visited;
int n;

void bfs(int sy, int sx, int type) {
    visited[sy][sx] = true;
    que.push({sy, sx});

    while(!que.empty()) {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();

        for(int i=0; i<4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(paint[ny][nx] != paint[cy][cx]) {
                if(type == 0) continue;
                if(type == 1) {
                    if(!((paint[ny][nx] == 'R' && paint[cy][cx] == 'G') || (paint[ny][nx] == 'G' && paint[cy][cx] == 'R'))) continue;
                }
            }
            if(visited[ny][nx]) continue;
            
            visited[ny][nx] = true;
            que.push({ny, nx});
        }
    }
}

int main(void) {
    scanf("%d", &n);

    for(int i=0; i<n; ++i)
        scanf(" %s", paint[i]);

    visited.resize(n);
    for(int i=0; i<n; ++i) visited[i].resize(n,false);

    int normalCnt = 0; 
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(!visited[i][j]) {
                ++normalCnt;
                bfs(i,j,0);
            }
        }
    }

    for(int i=0; i<n; ++i) fill(visited[i].begin(), visited[i].end(), false); 

    int cwCnt = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(!visited[i][j]) {
                ++cwCnt;
                bfs(i,j,1);
            }
        }
    }

    printf("%d %d", normalCnt, cwCnt);
}