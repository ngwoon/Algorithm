#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

queue<pair<int, int>> que;
bool visited[12][6];
char map[12][6];

void fall() {
    for(int i=0; i<6; i++) {
        for(int j=10; j>=0; j--) {
            if(map[j][i] != '.') {
                int index = j;
                while(1) { 
                    if(index == 11) break;
                    if(map[index + 1][i]=='.') ++index;
                    else break;
                }
                char temp = map[j][i];
                map[j][i] = '.';
                map[index][i] = temp;
            }
        }
    }
}

bool bfs(int y, int x) {
    vector<pair<int, int>> log;
    char cur = map[y][x];

    log.push_back({y, x});
    que.push({y, x});
    visited[y][x] = true;

    int cnt = 1;
    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx > 5 || ny < 0 || ny > 11)
                continue;
            if(visited[ny][nx])
                continue;
            if(map[ny][nx] != cur)
                continue;
            
            visited[ny][nx] = true;
            ++cnt;
            log.push_back({ny, nx});
            que.push({ny, nx});
        }
    }

    if(cnt >= 4) {
        for(int i=0; i<log.size(); i++)
            map[log[i].first][log[i].second] = '.';
        return true;
    }
    return false;
}

void reset() {
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            visited[i][j] = false;
}

int main(void) {
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            cin >> map[i][j];

    int answer = 0;
    while(1) {
        bool notBroken = true;
        for(int i=0; i<12; i++) {
            for(int j=0; j<6; j++) {
                if(map[i][j] != '.') {
                    if(bfs(i, j)) notBroken = false; 
                    reset();
                }
            }
        }
        if(!notBroken) ++answer;
        else break;
        fall();
    }
    cout << answer;
}
