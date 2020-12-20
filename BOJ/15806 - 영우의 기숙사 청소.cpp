#include <bits/stdc++.h>
using namespace std;

/*
    15806번 - 영우의 기숙사 청소

    기본적인 bfs로 풀면 시간초과 혹은 메모리초과가 나는 문제
    문제의 핵심은, 체스 "말" 과 같이 움직이므로, 현재 위치의 곰팡이가 사라져도, 어딘가에 전파만 됐다면 2일 뒤에는 돌아온다는 점이다.

    따라서 홀수 일과 짝수 일의 상태를 나타내는 2차원 배열 2개로 번갈아가며, 현재 곰팡이의 위치에서 전파될 수 있는 위치를 표시할 때
    사용중이지 않은 2차원배열에다가 표시하는 식으로 풀이하면 풀린다.
*/

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

queue<tuple<int, int, int>> que;
vector<pair<int, int>> virus;
vector<vector<bool>> visited[2];
vector<pair<int, int>> checkpoint;
int n,m,k,t;

void bfs() {
    int rnum=1;
    for(int i=0; i<m; ++i) { que.push({0, virus[i].first, virus[i].second}); visited[0][virus[i].first][virus[i].second]=true; }

    int day=0;
    while(!que.empty()) {
        int cnt = get<0>(que.front());
        int y = get<1>(que.front());
        int x = get<2>(que.front());
        que.pop();

        if(cnt == t) continue;
        if(cnt != day) {
            ++day;
            rnum ^= 1;
        }

        bool prop=false;
        for(int i=0; i<8; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 1 || ny > n || nx < 1 || nx > n) continue;
            if(visited[rnum][ny][nx]) continue;

            visited[rnum][ny][nx]=true; prop=true;
            que.push({cnt+1, ny, nx});
        }
        if(!prop) visited[rnum^1][y][x]=false;
    }
}

int main(void) {
    scanf("%d %d %d %d", &n, &m, &k, &t);
    
    virus.resize(m);
    for(int i=0; i<m; ++i) scanf(" %d %d", &virus[i].second, &virus[i].first);

    checkpoint.resize(k);
    for(int i=0; i<k; ++i) scanf(" %d %d", &checkpoint[i].second, &checkpoint[i].first);

    visited[0].resize(n+1);
    visited[1].resize(n+1);
    for(int i=1; i<=n; ++i) { visited[0][i].resize(n+1, false); visited[1][i].resize(n+1, false); }

    bfs();

    // for(int i=1; i<=n; ++i) {
    //     for(int j=1; j<=n; ++j) {
    //         printf("%d ", visited[i][j] ? 1 : 0);
    //     }
    //     printf("\n");
    // }
    
    for(int i=0; i<k; ++i) {
        if(visited[t%2][checkpoint[i].first][checkpoint[i].second]) { printf("YES"); exit(0); }
    }
    printf("NO");
}