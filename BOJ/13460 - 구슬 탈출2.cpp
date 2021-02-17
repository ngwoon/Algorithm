#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

typedef struct marblepos {
    int rx, ry, bx, by, cnt;
    marblepos(int _ry, int _rx, int _by, int _bx, int _cnt): rx(_rx), ry(_ry), bx(_bx), by(_by), cnt(_cnt) {};
}MARBLE_POS;

queue<MARBLE_POS> que;
bool visited[10][10][10][10];
char board[10][10];
int n,m;

pair<int, int> move(int y, int x, int opy, int opx, int dir) {
    // 동, 서 움직임
    if(dx[dir] != 0) {
        while((y != opy || x + dx[dir] != opx) && board[y][x + dx[dir]] == '.')
            x += dx[dir];
        if(board[y][x + dx[dir]] == 'O')
            x += dx[dir];
    }
    // 남, 북 움직임
    else {
        while((y + dy[dir] != opy || x != opx) && board[y + dy[dir]][x] == '.')
            y += dy[dir];
        if(board[y + dy[dir]][x] == 'O')
            y += dy[dir];
    }

    return {y, x};
}

int bfs(int ry, int rx, int by, int bx, int oy, int ox) {
    que.push({ry, rx, by, bx, 0});
    visited[ry][rx][by][bx] = true;

    while(!que.empty()) {
        int ry = que.front().ry;
        int rx = que.front().rx;
        int by = que.front().by;
        int bx = que.front().bx;
        int cnt = que.front().cnt;
        que.pop();

        if(cnt > 10)
            break;

        if(ry == oy && rx == ox)
            return cnt;
        
        // 동, 서, 남, 북
        for(int i=0; i<4; ++i) {
            pair<int, int> nrpos;
            pair<int, int> nbpos;

            if(i == 0 && ry == by) {
                if(rx < bx) {
                    nbpos = move(by, bx, ry, rx, i);
                    nrpos = move(ry, rx, nbpos.first, nbpos.second, i);
                } else {
                    nrpos = move(ry, rx, by, bx, i);
                    nbpos = move(by, bx, nrpos.first, nrpos.second, i);
                }
            } else if(i == 1 && ry == by) {
                if(rx < bx) {
                    nrpos = move(ry, rx, by, bx, i);
                    nbpos = move(by, bx, nrpos.first, nrpos.second, i);
                } else {
                    nbpos = move(by, bx, ry, rx, i);
                    nrpos = move(ry, rx, nbpos.first, nbpos.second, i);
                }
            } else if(i == 2 && rx == bx) {
                if(ry < by) {
                    nbpos = move(by, bx, ry, rx, i);
                    nrpos = move(ry, rx, nbpos.first, nbpos.second, i);
                } else {
                    nrpos = move(ry, rx, by, bx, i);
                    nbpos = move(by, bx, nrpos.first, nrpos.second, i);
                }
            } else if(i == 3 && rx == bx) {
                if(ry < by) {
                    nrpos = move(ry, rx, by, bx, i);
                    nbpos = move(by, bx, nrpos.first, nrpos.second, i);
                } else {
                    nbpos = move(by, bx, ry, rx, i);
                    nrpos = move(ry, rx, nbpos.first, nbpos.second, i);
                }
            } else {
                nrpos = move(ry, rx, by, bx, i);
                nbpos = move(by, bx, ry, rx, i);
            }

            int nry = nrpos.first;
            int nrx = nrpos.second;
            int nby = nbpos.first;
            int nbx = nbpos.second;
            int ncnt = cnt + 1;
    
            if(visited[nry][nrx][nby][nbx])
                continue;
            // 파 구슬이 홀 통과하는 경우
            if(nby == oy && nbx == ox)
                continue;
            
            visited[nry][nrx][nby][nbx] = true;
            que.push({nry, nrx, nby, nbx, ncnt});
        }
    }

    return -1;
}

int main(void) {
    scanf("%d %d", &n, &m);
    
    int rx, ry, bx, by, ox, oy;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'R') {
                rx = j; ry = i;
            } else if(board[i][j] == 'B') {
                bx = j; by = i;
            } else if(board[i][j] == 'O') {
                ox = j; oy = i;
            }
            
            if(board[i][j] != '#' && board[i][j] != 'O')
                board[i][j] = '.';
        }
    }
    

    printf("%d", bfs(ry, rx, by, bx, oy, ox));
}