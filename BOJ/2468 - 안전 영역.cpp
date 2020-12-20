#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n, rain, area, ans;
int field[100][100];
queue<pair<int, int>> que;
vector<vector<bool>> visited; 

void bfs(int i, int j) {
    visited[i][j] = true;
    que.push({i,j});

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();  

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(field[ny][nx] <= rain) continue; 
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;
            que.push({ny, nx});
        }
    }
    ++area;
}

int main(void) {

    int shortest=101, tallest=0;

    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            scanf(" %d", &field[i][j]);
            shortest = min(shortest, field[i][j]);
            tallest = max(tallest, field[i][j]);
        }
    }

    visited.resize(n);
    for(int i=0; i<n; ++i)
        visited[i].resize(n, false);

    for(int i=shortest; i<=tallest; ++i) {
        rain = i; area = 0;
        for(int j=0; j<n; ++j) {
            for(int k=0; k<n; ++k) {
                if(!visited[j][k] && field[j][k] > rain)
                    bfs(j,k);
            }
        }
        if(area == 0)
            area = 1;
        ans = max(ans, area);
        for(int i=0; i<n; ++i)
            fill(visited[i].begin(), visited[i].end(), false);
    }
    printf("%d", ans);
}  