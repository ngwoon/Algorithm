#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool field[100][100];
bool visited[100][100];
queue<pair<int, int>> que; 
int m,n,k;

int bfs(int sy, int sx) {
    visited[sy][sx] = true;
    que.push({sy, sx});

    int area = 0;
    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        ++area;

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;
            if(visited[ny][nx] || !field[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            que.push({ny,nx});
        }
    }
    return area;
}

int main(void) {
    scanf("%d %d %d", &m, &n, &k);

    for(int i=0; i<m; ++i)
        memset(field[i], true, n);
    
    for(int i=0; i<k; ++i) {
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        for(int j=sy; j<ey; ++j) {
            for(int p=sx; p<ex; ++p)
                field[j][p] = false;
        }
    }

    int cnt=0;
    vector<int> area;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(!field[i][j] || visited[i][j])
                continue;
            ++cnt;
            area.push_back(bfs(i,j)); 
        }
    }
    sort(area.begin(), area.end());
    printf("%d\n", cnt);
    for(int i=0; i<area.size(); ++i)
        printf("%d ", area[i]);
}