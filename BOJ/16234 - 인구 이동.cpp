#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int field[50][50];
bool visited[50][50];
queue<pair<int, int>> que;
int n, L, R;

bool bfs(int sy, int sx) {
    vector<pair<int, int>> alley;
    visited[sy][sx] = true;
    que.push({sy,sx});
    alley.push_back({sy,sx});
    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(visited[ny][nx]) continue;

            int gap = abs(field[y][x] - field[ny][nx]);
            if(gap < L || gap > R) continue;

            visited[ny][nx] = true;
            que.push({ny,nx});
            alley.push_back({ny,nx});
        }
    }

    int s = alley.size();
    if(s != 1) {
        int sum=0;
        for(int i=0; i<alley.size(); ++i)
            sum += field[alley[i].first][alley[i].second];
        
        int population = sum/s;
        for(int i=0; i<alley.size(); ++i)
            field[alley[i].first][alley[i].second] = population;

        return true;
    }

    return false;
}

int main(void) {
    scanf("%d %d %d", &n, &L, &R);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            scanf("%d", &field[i][j]);
    }
    
    int ans=0;
    while(1) {
        bool allComp=true;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(visited[i][j]) continue;
                if(bfs(i,j)) {
                    allComp=false;
                    ++ans;
                }
            }
        }
        if(allComp)
            break;
        for(int i=0; i<n; ++i)
            memset(visited[i], false, n);
    }

    printf("%d", ans);
}