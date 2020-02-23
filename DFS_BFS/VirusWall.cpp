#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

char map[8][8];
char tempMap[8][8];
vector<pair<int, int>> vpos; // 행, 렬순 저장 (y,x)
queue<pair<int,int>> que;

vector<int> results;

int N, M;

void bfs(int row, int col) {
    que.push({row,col});

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        //cout << "(y, x) = " << "(" << y << ", " << x << ")" << endl;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            
            if(tempMap[ny][nx] != '0')
                continue;

            tempMap[ny][nx] = '2';

            que.push({ny, nx});
        }
    }
}

void copyMap() {
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            tempMap[i][j] = map[i][j];
}

void printMap() {

    cout << "tempMap" << endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cout << tempMap[i][j];
        cout << "\n";
    }

    // cout << "Original Map" << endl;
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<M; j++)
    //         cout << map[i][j];
    //     cout << "\n";
    // }

    system("pause");
}

void countSafeArea() {
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(tempMap[i][j] == '0')
                ++cnt;
        }
    }

    results.push_back(cnt);
}

int main(void) {
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];

            if(map[i][j] == '2')
                vpos.push_back({i, j});
        }
    }

    // i,j,k = 세워야 할 3개 벽의 위치
    for(int i=0; i<N*M - 2; i++) {
        for(int j=i+1; j<N*M - 1; j++) {
            for(int k=j+1; k<M*N; k++) {

                pair<int, int> walls[3] = {{i/M, i%M}, {j/M, j%M}, {k/M, k%M}};

                
                if(map[walls[0].first][walls[0].second] != '0')
                    continue;
                else if(map[walls[1].first][walls[1].second] != '0')
                    continue;
                else if(map[walls[2].first][walls[2].second] != '0')
                    continue;

                copyMap();

                //벽 세우기
                for(int m=0; m<3; m++)
                    tempMap[walls[m].first][walls[m].second] = '1';

                //printMap();

                for(int m=0; m<vpos.size(); m++)
                    bfs(vpos[m].first, vpos[m].second);
                
                countSafeArea();
            }
        }
    }

    cout << *max_element(results.begin(), results.end());

    return 0;
}