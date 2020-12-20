#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

char field[50][50];
bool visited[50][50];
queue<pair<int, int>> que;
int w,h;

void bfs(int sy, int sx) {
    visited[sy][sx] = true;
    que.push({sy,sx});

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for(int i=0; i<8; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
            if(field[ny][nx] == '0')
                continue;
            if(visited[ny][nx])
                continue;

            visited[ny][nx] = true;
            que.push({ny, nx});
        }
    }
}

int main(void) {
    while(1) {
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0)
            return 0;

        for(int i=0; i<h; ++i) {
            for(int j=0; j<w; ++j)
                scanf(" %c", &field[i][j]);
        }

        for(int i=0; i<h; ++i)
            memset(visited[i], false, w);

        int cnt=0;
        for(int i=0; i<h; ++i) {
            for(int j=0; j<w; ++j) {
                if(visited[i][j])
                    continue;
                if(field[i][j] == '0')
                    continue;

                ++cnt; bfs(i,j);
            }
        }
        printf("%d\n", cnt);
    }
}