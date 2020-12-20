// #include <bits/stdc++.h>
// using namespace std;

// int dx[4] = {0,0,-1,1};
// int dy[4] = {-1,1,0,0};

// queue<pair<int, pair<int, int>>> que;
// vector<vector<bool>> visited;
// char field[20][20];
// int N,M;
// int ans=987654321;

// int bfs(pair<int, int> s1, pair<int, int> s2) {
//     que.push({0, s1});
//     que.push({0, s2});
//     visited[s1.first][s1.second]=true;
//     visited[s2.first][s2.second]=true;

//     int res=0;
//     while(!que.empty()) {
//         int y = que.front().second.first;
//         int x = que.front().second.second;
//         int cnt = que.front().first;
//         que.pop();

//         if(field[y][x] == '1' && res < cnt) res = cnt;

//         for(int i=0; i<4; ++i) {
//             int ny = y + dy[i];
//             int nx = x + dx[i];

//             if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
//             if(visited[ny][nx]) continue;

//             visited[ny][nx] = true;
//             que.push({cnt+1, {ny,nx}});
//         }
//     }

//     return res;
// }

// int main(void) {
//     cin.sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N >> M;

//     visited.resize(N);
//     for(int i=0; i<N; ++i) visited[i].resize(M, false);
//     for(int i=0; i<N; ++i)
//         for(int j=0; j<M; ++j)
//             cin >> field[i][j];
    
//     for(int i=0; i<N; ++i) {
//         for(int j=0; j<M; ++j) {
//             if(field[i][j] == '1') continue;
//             int k=i;
//             int m=j+1;

//             while(1) {
//                 if(m >= M) { ++k; m=0; }
//                 if(k >= N) break;
//                 if(field[k][m] == '1') { ++m; continue; }
                
//                 pair<int, int> s2 = {k, m};

//                 int res = bfs({i,j}, s2);

//                 if(ans > res) ans = res;

//                 for(int i=0; i<N; ++i) fill(visited[i].begin(), visited[i].end(), false);
//                 ++m;
//             }
//         }
//     }
//     cout << ans;
// }


#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> towns;
char field[20][20];
int N,M;
int ans=987654321;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> field[i][j];
            if(field[i][j] == '1') towns.push_back({i,j});
        }
    }
    
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(field[i][j] == '1') continue;
            
            int k = i;
            int m = j+1;
            while(1) {
                if(m >= M) { ++k; m=0; }
                if(k >= N) break;

                if(field[k][m] == '1') { ++m; continue; }
                
                int far=0;
                for(int r=0; r<towns.size(); ++r) {
                    int ty = towns[r].first;
                    int tx = towns[r].second;
                    far = max(far, min(abs(ty-i) + abs(tx-j), abs(ty-k) + abs(tx-m)));
                }
                ans = ans > far ? far : ans;
                ++m;
            }
        }
    }
    cout << ans;
}