#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

queue<pair<int, int>> que;
int box[1000][1000];
vector<vector<bool>> visited;
int m,n;
int ans=-1;

void bfs() {
    while(!que.empty()) {
        ++ans;
        queue<pair<int, int>> temp;
        while(!que.empty()) {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for(int i=0; i<4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(box[ny][nx] == -1) continue;
                if(visited[ny][nx]) continue;

                visited[ny][nx]=true;
                temp.push({ny,nx});
            }
        }
        while(!temp.empty()) { que.push(temp.front()); temp.pop(); }
    }
}

int main(void) {
    scanf("%d %d", &m, &n);

    visited.resize(n);
    for(int i=0; i<n; ++i) visited[i].resize(m,false);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            scanf(" %d", &box[i][j]);
            if(box[i][j] == 1) { visited[i][j] = true; que.push({i,j}); }
        }
    }

    bfs();

    bool isAllDone=true;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(!visited[i][j] && box[i][j] == 0) { isAllDone=false; break; }
        }
    }
    if(isAllDone) printf("%d", ans);
    else printf("-1");
}