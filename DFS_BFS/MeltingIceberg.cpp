#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int map[300][300];
int tempMap[300][300];
bool visited[300][300];

queue<pair<int, int>> que;

int N, M;

// NOTYET : 빙산 구역이 둘로 나뉘지 않았다.
// DIVIDED : 빙산 구역이 둘 이상으로 나뉘었다.
// CANNNOT : 빙산 구역이 둘 이상으로 나뉘기 전 모든 빙산이 사라졌다.
enum STATUS {NOTYET, DIVIDED, CANNOT};

STATUS bfs() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] != 0) {
                que.push({i, j});
                visited[i][j] = true;
                goto START;
            }
        }
    }

START:

    // 모든 맵이 0이면 CANNOT 반환
    if(que.empty())
        return CANNOT;

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;

            if(map[ny][nx] == 0 || visited[ny][nx])
                continue;
            
            visited[ny][nx] = true;

            que.push({ny, nx});
        }
    }

    // 1회 bfs를 했음에도 방문하지 못한 빙산이 있다면 빙산 구역이 2개 이상으로 나뉘었다는 뜻
    // 선형 탐색으로 방문 안 된 빙산이 존재하는지 확인
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!visited[i][j] && map[i][j] > 0)
                return DIVIDED;
        }
    }

    // 위 for문에서 리턴되지 못했다는 건 빙산 구역이 하나라는 의미
    // NOTYET를 리턴하여 main에서 결과를 출력하지 않게 만든다. 
    return NOTYET;
}

void yearAfter() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] > 0) {
                int nx, ny;
                for(int k=0; k<4; k++) {
                    nx = j + dx[k];
                    ny = i + dy[k];

                    if(nx < 0 || nx >= M || ny < 0 || ny >= N)
                        continue;
                    
                    if(tempMap[ny][nx] == 0)
                        --map[i][j];
                }

                if(map[i][j] < 0)
                    map[i][j] = 0;
            }
        }
    }

    // 변화된 맵으로 tempMap 초기화
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            tempMap[i][j] = map[i][j];
}

int main(void) {
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            tempMap[i][j] = map[i][j];
        }
    }
    
    int cnt = 1;
    while(1) {
        yearAfter();

        switch(bfs()) {
            case NOTYET : break;
            case DIVIDED : cout << cnt; exit(0);
            case CANNOT : cout << 0; exit(0);
        }

        // visited배열 초기화
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++)
                visited[i][j] = false;
        }

        ++cnt;
    }
}