#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 상, 좌, 하, 우
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

typedef struct info {
    pair<int, int> rpos;
    pair<int, int> bpos;
    int cnt;
}INFO;

char map[10][10];
bool visited[8][8][8][8];
int N,M;

queue<INFO> que;

// 벽에 부딪힌 상황, 두 구슬이 겹치는 상황 체크
// 두 구슬 모두 움직임이 없으면 false, 둘 중 하나라도 움직였으면 true 반환
bool check(int* nrx, int* nry, int* nbx, int* nby, int rx, int ry, int bx, int by) {

    bool result = true;

    // 벽 못지나가게 설정
    // 벽에 부딪혔을 경우 해당 구슬을 본래 자리로
    if(map[*nry][*nrx] == '#') {
        *nrx = rx; *nry = ry;
    }
    if(map[*nby][*nbx] == '#') {
        *nbx = bx; *nby = by;
    }

    // 두 구슬이 겹쳐버린 상황
    if(*nrx == *nbx && *nry == *nby) {
        // 빨간 구슬이 벽에 부딪혀 움직이지 못한 경우 -> 파란 구슬을 본래 자리로
        // 파란 구슬이 벽에 부딪혀 움직이지 못한 경우 -> 빨간 구슬을 본래 자리로
        if(*nrx == rx && *nry == ry) {
            *nbx = bx;
            *nby = by;
        } else {
            *nrx = rx;
            *nry = ry;
        }
    }

    // 검사 후 두 구슬 모두 본래 위치인 경우 false 반환 
    if(*nrx == rx && *nry == ry && *nbx == bx && *nby == by)
        result = false;

    // cout << "========================" << endl;
    // cout << "(nry, nrx) = " << "(" << *nry << ", " << *nrx << ")" << endl;
    // cout << "(nby, nbx) = " << "(" << *nby << ", " << *nbx << ")" << endl;
    // cout << "========================" << endl;
    // system("pause");

    return result;
}

// -1 : 파란 구슬이 홀 안으로 (빨간 구슬과 동시에 들어가는 경우 포함)
// 0 : 두 구슬 모두 홀에 들어가지 못함
// 1 : 빨간 구슬이 홀 안으로
int isInHall(int rx, int ry, int bx, int by) {
    int result = 0;

    if(map[ry][rx] == 'O')
        result = 1;
    if(map[by][bx] == 'O')
        result = -1;

    return result;
}

void bfs(INFO start) {

    start.cnt = 0;
    que.push(start);

    visited[start.rpos.first][start.rpos.second][start.bpos.first][start.bpos.second] = true;

    while(!que.empty()) {
L1:
        int ry = que.front().rpos.first;
        int rx = que.front().rpos.second;
        int by = que.front().bpos.first;
        int bx = que.front().bpos.second;
        int cnt = que.front().cnt;

        que.pop();

        // cout << "============new turn============" << endl;
        // cout << "(ry, rx) = " << "(" << ry << ", " << rx << ")" << endl;
        // cout << "(by, bx) = " << "(" << by << ", " << bx << ")" << endl;
        // cout << "cnt = " << cnt << endl;
        // cout << "========================" << endl;

        // system("pause");

        if(cnt > 10) {
            cout << "-1";
            exit(0);
        }   

        for(int i=0; i<4; i++) {
L2:                      
            int nry = ry, nrx = rx, nby = by, nbx = bx;

            while(1) {

                // 구슬 이동 검사를 위해 구슬의 바로 전 위치 저장
                int bef_nry = nry;
                int bef_nrx = nrx;
                int bef_nby = nby;
                int bef_nbx = nbx;

                nry = nry + dy[i];
                nrx = nrx + dx[i];
                nby = nby + dy[i];
                nbx = nbx + dx[i];

                // 두 구슬 모두 이동 못했으면 이동 중지
                if(!check(&nrx, &nry, &nbx, &nby, bef_nrx, bef_nry, bef_nbx, bef_nby))
                    break;

                int res = isInHall(nrx, nry, nbx, nby);
                
                if(res == -1) {
L3:                 
                    if(++i == 4) goto L1; 
                    else goto L2;
                } else if(res == 1) {
                    while(map[nby][nbx] != '#') {
                        nby += dy[i];
                        nbx += dx[i];

                        if(map[nby][nbx] == 'O')
                            goto L3;
                    }

                    cout << cnt + 1;
                    exit(0);
                }
            }

            if(visited[nry][nrx][nby][nbx])
                continue;

            visited[nry][nrx][nby][nbx] = true;
            
            que.push({{nry, nrx}, {nby, nbx}, cnt + 1});
        }
    }

    cout << -1;
}

int main(void) {
    cin >> N >> M;

    INFO start;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];

            if(map[i][j] == 'R') {
                start.rpos.first = i;
                start.rpos.second = j;
            }
            else if(map[i][j] == 'B') {
                start.bpos.first = i;
                start.bpos.second = j;
            }
        }
    }

    for(int i=0; i<N - 2; i++) {
        for(int j=0; j<M - 2; j++) {
            for(int k=0; k<N - 2; k++)
                memset(visited[i][j][k], false, sizeof(bool)*(M - 2));
        }
    }

    bfs(start);
}