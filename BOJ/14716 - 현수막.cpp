#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0,0,-1,1,-1,1,1,-1};
int dy[8] = {-1,1,0,0,-1,-1,1,1};

queue<pair<int, int>> que;
vector<vector<bool>> visited;
char banner[250][250];
int M, N;

void bfs(int sy, int sx) {
    que.push({sy, sx});
    visited[sy][sx]=true;

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for(int i=0; i<8; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(banner[ny][nx] == '0') continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;
            que.push({ny, nx});
        }
    }
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;

    for(int i=0; i<M; ++i)
        for(int j=0; j<N; ++j)
            cin >> banner[i][j];

    visited.resize(M);
    for(int i=0; i<M; ++i) visited[i].resize(N, false);

    int cnt=0;
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            if(banner[i][j] == '1' && !visited[i][j]) { bfs(i, j); ++cnt; }
        }
    }

    cout << cnt;
}