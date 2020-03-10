#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

queue<pair<int, int>> swanQ;
queue<pair<int, int>> swanNQ;
queue<pair<int, int>> waterQ;
queue<pair<int, int>> waterNQ;
vector<vector<bool>> visited;
vector<vector<bool>> checked;
vector<pair<int, int>> swan;
char field[1500][1500];
int R,C;
int ans=0;

void water_bfs() {
    while(!waterQ.empty()) {
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();

        field[y][x] = '.';

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
            if(checked[ny][nx]) continue;
            if(field[ny][nx] == 'X') { checked[ny][nx]=true; waterNQ.push({ny,nx}); }
        }
    }
}

void swan_bfs() {
    while(!swanQ.empty()) {
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();

        if(y == swan[1].first && x == swan[1].second) break;

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(visited[ny][nx]) continue;

            if(field[ny][nx] == 'X') { visited[ny][nx]=true; swanNQ.push({ny,nx}); continue; }

            visited[ny][nx]=true;
            swanQ.push({ny, nx});
        }
    }
}

void printMap() {
    printf("=================\n");
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
    printf("=================\n");
}

int main(void) {
    scanf("%d %d", &R, &C); getchar();

    visited.resize(R); checked.resize(R);
    for(int i=0; i<R; ++i) { visited[i].resize(C, false); checked[i].resize(C, false); }

    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) scanf("%c", &field[i][j]);
        getchar();
    }

    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            if(field[i][j] != 'X') {
                checked[i][j]=true;
                for(int k=0; k<4; ++k) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                    if(checked[ni][nj]) continue;
                    if(field[ni][nj] != 'X') continue;
                    
                    if(ni == 0 && nj == 14) printf("sdfsd");
                    checked[ni][nj]=true;
                    waterQ.push({ni,nj});
                }
            }
            if(field[i][j] == 'L') {
                swan.push_back({i,j});
                if(swanQ.empty()) { visited[i][j]=true; swanQ.push({i,j}); }
            }
        }
    }

    while(1) {
        swan_bfs();
        if(visited[swan[1].first][swan[1].second]) break;

        ++ans;
        water_bfs();

        printMap();

        waterQ = waterNQ;
        swanQ = swanNQ;
        while(!waterNQ.empty()) waterNQ.pop();
        while(!swanNQ.empty()) swanNQ.pop();
    }
    printf("%d", ans);
}