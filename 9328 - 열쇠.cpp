#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

typedef struct info {
    int y, x, cnt;
}INFO;

queue<INFO> que;
string key;
char building[102][102];
bool visited[102][102];
int t,h,w;
int ans;

void bfs() {
    while(!que.empty()) que.pop();
    
    que.push({0,0,0});
    while(!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        int cnt = que.front().cnt;
        que.pop();

        for(int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            char cur = building[ny][nx];
            
            if(ny < 0 || ny > h+1 || nx < 0 || nx > w+1) continue;
            if(cur == '*' || visited[ny][nx]) continue;

            if(cur >= 'A' && cur <= 'Z') {
                if(binary_search(key.begin(), key.end(), tolower(cur))) building[ny][nx] = '.';
                else continue;
            }
            else if(cur >= 'a' && cur <= 'z') {
                building[ny][nx] = '.';
                if(!binary_search(key.begin(), key.end(), cur)) {
                    key.insert(upper_bound(key.begin(), key.end(), cur), cur);

                    while(!que.empty()) que.pop();
                    for(int j=0; j<=h+1; ++j) memset(visited[j], false, w+2);
                }
            }
            else if(cur == '$') {
                ++ans;
                building[ny][nx] = '.';
            }

            visited[ny][nx]=true;
            que.push({ny, nx});
        }
    }
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;

    for(int i=0; i<t; ++i) {
        ans=0;

        cin >> h >> w;
        for(int j=0; j<=h+1; ++j) {
            for(int k=0; k<=w+1; ++k) {
                if(j == 0 || j == h+1 || k == 0 || k == w+1) building[j][k] = '.';
                else cin >> building[j][k];
            }
        }
        cin >> key;

        sort(key.begin(), key.end());

        for(int j=0; j<=h+1; ++j) memset(visited[j], false, w+2);

        bfs();

        cout << ans << "\n";
    }
}