#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

queue<pair<pair<bool, int>, pair<int, int>>> que;
vector<vector<bool>> visited[2];
vector<vector<char>> maze;
int n,m;
int hy,hx,ey,ex;

void bfs() {
    if(maze[hy][hx] == '1') { que.push({{0,0},{hy,hx}}); visited[0][hy][hx]=true; }
    else { que.push({{1,0},{hy,hx}}); visited[1][hy][hx]=true; }

    while(!que.empty()) {
        int usable = que.front().first.first;
        int cnt = que.front().first.second;
        int y = que.front().second.first;
        int x = que.front().second.second;
        que.pop();

        // printf("y,x,cnt : %d,%d,%d\n", y,x,cnt);
        // printf("usable : %s\n\n", usable ? "true" : "false");
        // if(y == ey && x == ex) { printf("%d", cnt); exit(0); }

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 1 || ny > n || nx < 1 || nx > m) continue;
            if(maze[ny][nx] == '1') {
                if(usable == 0) continue;
                if(visited[usable^1][ny][nx]) continue;

                visited[usable^1][ny][nx]=true;
                que.push({{usable^1,cnt+1}, {ny,nx}});
                continue;
            }

            if(visited[usable][ny][nx]) continue;
            visited[usable][ny][nx]=true;
            que.push({{usable,cnt+1}, {ny,nx}});            
        }
    }
    printf("-1");
}

int main(void) {
    scanf("%d %d", &n, &m);
    scanf(" %d %d", &hy, &hx);
    scanf(" %d %d", &ey, &ex);
    maze.resize(n+1);
    visited[0].resize(n+1);
    visited[1].resize(n+1);
    for(int i=1; i<=n; ++i) { maze[i].resize(m+1); visited[0][i].resize(m+1,false); visited[1][i].resize(m+1,false); }
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=m; ++j)
            scanf(" %c", &maze[i][j]);

    bfs();
}