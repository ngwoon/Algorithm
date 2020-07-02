#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int dx[2] = {1, 0};
int dy[2] = {0, 1};

queue<pair<pair<int, int>, pair<int, int>>> que;
vector<vector<int>> dst;
vector<vector<int>> market;
int N;

void bfs() {
    if(market[0][0] == 0) { dst[0][0] = 1; que.push({{1,1},{0,0}}); }
    else { dst[0][0] = 0; que.push({{0,0},{0,0}}); }
    while(!que.empty()) {
        int cnt = que.front().first.first;
        int curMilk = que.front().first.second;
        int y = que.front().second.first;
        int x = que.front().second.second;
        que.pop();
        
        if(dst[y][x] > cnt) continue;

        for(int i=0; i<2; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int ncnt=cnt, nextMilk=curMilk;
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            
            if(market[ny][nx] == nextMilk) { ++ncnt; nextMilk = (nextMilk+1)%3; }
            if(dst[ny][nx] >= ncnt) continue;

            dst[ny][nx] = ncnt;
            que.push({{ncnt, nextMilk}, {ny, nx}});
        }
    }
}

int main(void) {
    scanf("%d", &N);

    market.resize(N);
    dst.resize(N);
    for(int i=0; i<N; ++i) { market[i].resize(N); dst[i].resize(N, -1); }

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            scanf(" %d", &market[i][j]);

    bfs();

    printf("%d", dst[N-1][N-1]);

}