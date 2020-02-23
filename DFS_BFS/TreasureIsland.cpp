#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int N, M;
char map[50][50];
bool visited[50][50];

vector<int> candidate;
queue<pair<pair<int, int>, int>> que;

void bfs(int y, int x) {
    que.push({{y, x}, 0});

    visited[y][x] = true;

    int far = 0;
    while(!que.empty()) {
        int cy = que.front().first.first;
        int cx = que.front().first.second;
        int cdst = que.front().second;

        que.pop();

        if(far < cdst)
            far = cdst;

        for(int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            if(visited[ny][nx] || map[ny][nx] == 'W')
                continue;

            visited[ny][nx] = true;

            que.push({{ny, nx}, cdst + 1});
        }
    }

    candidate.push_back(far);
}

//visited 정리
void reset() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            visited[i][j] = false;
    }
}


int main(void) {
    cin >> N >> M;

    int initVal = M*N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == 'L')
                bfs(i, j);

                //visited, candidate 정리 필요
                reset();
        }
    }

    //candidate 내에서 dst가 가장 큰 두 Land를 보물섬으로 지정
    //선형탐색
    int maxDst = 0;
    for(int i=0; i<candidate.size(); i++) {
        if(maxDst < candidate[i]) {
            maxDst = candidate[i];
        }
    }

    cout << maxDst;
    
    return 0;
}