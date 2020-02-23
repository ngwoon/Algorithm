#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
물과 고슴도치의 움직임 모두 신경써야 하는 문제
물과 고슴도치가 겹치면 안된다.
즉, 물을 먼저 이동시킨 후 고슴도치를 이동시키면, 고슴도치가 갈 수 없는 방향으로 가는 경우의 수를 줄일 수 있다.

queue 하나로 물과 고슴도치의 bfs를 동시에 진행한다.
물의 초기 위치를 queue에 먼저 넣어서, 물 -> 고슴도치 순서로 bfs가 진행되게끔 한다.
bfs이므로 고슴도치가 가장 먼저 D에 도달하면 그것이 최단거리임이 보장된다. 이 때 count를 출력 후 프로그램을 종료한다.
아울러 queue가 비워질 때 까지 도착하지 못하면 도착할 수 없는 경우이므로 while문이 끝난 후 KAKTUS를 출력한다.
*/

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

// isWater이 true 이면 물, 아니면 고슴도치 위치에 대한 정보
typedef struct info {
    int y, x;
    int cnt;
    bool isWater;
}INFO;

int N, M;
char map[50][50];
bool visited[50][50];

pair<int, int> start;
pair<int, int> dst;

queue<INFO> que;

void printMap() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cout << map[i][j];
        cout << endl;
    }
}

void bfs() {
    que.push({start.first, start.second, 0, false});

    visited[start.first][start.second] = true;

    while(!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        int cnt = que.front().cnt;
        bool isWater = que.front().isWater;

        que.pop();

        if(y == dst.first && x == dst.second) {
            cout << cnt;
            exit(0);
        }

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;

            if(!isWater) {
                if(map[ny][nx] == '*' || map[ny][nx] == 'X')
                    continue;
                if(visited[ny][nx])
                    continue;

                visited[ny][nx] = true;
            } else {
                if(map[ny][nx] == '*' || map[ny][nx] == 'X' || map[ny][nx] == 'D')
                    continue;

                map[ny][nx] = '*';
            }

            que.push({ny, nx, cnt + 1, isWater});
        }
    }

    cout << "KAKTUS";
}

int main(void) {
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];

            // 물의 첫 위치 기록
            if(map[i][j] == '*')
                que.push({i, j, 0, true});
            else if(map[i][j] == 'D')
                dst = {i, j};
            else if(map[i][j] == 'S')
                start = {i, j};
        }
    }

    bfs();
}