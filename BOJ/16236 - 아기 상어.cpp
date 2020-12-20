#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};

struct info {
    int y, x, m;
};

struct comp {
    bool operator() (struct info& a, struct info& b) {
        if(a.m != b.m)
            return a.m > b.m;
        else if(a.y == b.y)
            return a.x > b.x;
        return a.y > b.y;
    }
};

vector<vector<int>> field;
vector<vector<bool>> visited;
priority_queue<struct info, vector<struct info>, comp> que;
int n,y,x,ans,curEat,curSize=2;

bool bfs() {
    visited[y][x] = true;
    que.push({y, x, 0});

    while(!que.empty()) {
        int cy = que.top().y;
        int cx = que.top().x;
        int m = que.top().m;
        que.pop();

        if(field[cy][cx] > 0 && field[cy][cx] < curSize) {
            field[cy][cx] = 0;
            ans += m; y = cy; x = cx; ++curEat;

            if(curEat == curSize) {
                ++curSize; curEat=0;
            }

            while(!que.empty())
                que.pop();
                
            return true;
        }

        for(int i=0; i<4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(field[ny][nx] > curSize) continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;
            que.push({ny, nx, m+1});
        }
    }
    return false;
}

int main(void) {
    scanf("%d", &n);

    field.resize(n);
    for(int i=0; i<n; ++i)
        field[i].resize(n, 0);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            scanf("%d", &field[i][j]);
            if(field[i][j] == 9) {
                y = i; x = j; field[i][j] = 0;
            }
        }
    }

    visited.resize(n);
    for(int i=0; i<n; ++i)
        visited[i].resize(n, false);

    while(bfs()) {
        for(int i=0; i<n; ++i)
            fill(visited[i].begin(), visited[i].end(), false);
    }

    printf("%d", ans);
}