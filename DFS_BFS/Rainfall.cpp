#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

/*
아예 비가 오지 않을 경우도 고려해야 했던 문제
*/


using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int map[101][101];
pair<int, bool> tempMap[101][101]; // second : 물에 잠긴 여부. true이면 물에 잠겼다는 뜻
bool visited[101][101];
vector<int> result;

queue<pair<int, int>> que;

int N;

void rain(int prci) {
    for(int i=1; i<N + 1; i++) {
        for(int j=1; j<N + 1; j++) {
            tempMap[i][j].first = map[i][j];
            tempMap[i][j].second = prci >= map[i][j] ? true : false;
            visited[i][j] = false;
        }
    }
}

void bfs(int row, int col) {
    
    que.push({row, col});

    while(!que.empty()) {
        int x = que.front().second;
        int y = que.front().first;

        que.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > N)
                continue;

            // 해당 도시가 잠겼거나 이미 방문한 도시이면 pass
            if(tempMap[ny][nx].second || visited[ny][nx])
                continue;

            visited[ny][nx] = true;

            que.push({ny, nx});
        }
    }
}

int main(void) {

    cin >> N;

    int maxVal = 0;
    for(int i=1; i<N + 1; i++) {
        for(int j=1; j<N + 1; j++) {
            cin >> map[i][j];
        
            if(maxVal < map[i][j])
                maxVal = map[i][j];
        }
    }

    for(int i=0; i<maxVal; i++) {

        int cnt = 0;
        
        //tempMap, visited 초기화 및 i이하의 높이 도시 물에 잠김 표기
        rain(i);

        for(int j=1; j<N + 1; j++) {
            for(int k=1; k<N + 1; k++) {
                if(!tempMap[j][k].second && !visited[j][k]) {
                    bfs(j, k);
                    ++cnt;
                }
            }
        }

        result.push_back(cnt);
    }

    cout << *max_element(result.begin(), result.end());
}