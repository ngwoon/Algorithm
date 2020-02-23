#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

// 시계방향순 8가지 + 상하좌우
int dx[12] = {1, 2, 2, 1, -1, -2, -2, -1, 0, 0, -1, 1};
int dy[12] = {-2, -1, 1, 2, 2, 1, -1, -2, -1, 1, 0, 0};

typedef struct info {
    // use : 말 움직임 사용 횟수
    int y, x, cnt, use;
}INFO;

queue<INFO> que; 
char map[200][200];
bool visited[31][200][200];
int K, W, H;\

void bfs() {
    que.push({0,0,0,0});
    visited[0][0][0] = true;

    while(!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        int cnt = que.front().cnt;
        int use = que.front().use;
        que.pop();

        if(y == H - 1 && x == W - 1) {
            printf("%d", cnt);
            exit(0);
        }

        for(int i=0; i<12; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nu = ((i < 8) ? use + 1 : use);

            if(nu > K) continue;
            if(nx < 0 || nx >= W || ny < 0 || ny >= H || map[ny][nx]=='1') continue;
            if(visited[nu][ny][nx]) continue;

            visited[nu][ny][nx] = true;
            que.push({ny, nx, cnt + 1, nu});
        }
    }
    printf("-1");
}

int main(void) {
    scanf("%d %d %d", &K, &W, &H);

    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            scanf(" %c", &map[i][j]);

    bfs();
}