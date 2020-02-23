#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[101];

bool visited[101];

int N;
int start, dst;

queue<pair<int, int>> que;

void bfs() {
    que.push({start, 0});

    visited[start] = true;

    while(!que.empty()) {
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if(cur == dst) {
            cout << cnt;
            exit(0);
        }

        int rel = adj[cur].size();
        for(int i=0; i<rel; i++) {
            if(visited[adj[cur][i]])
                continue;

            visited[adj[cur][i]] = true;

            que.push({adj[cur][i], cnt + 1});
        }
    }

    cout << -1;
}

int main(void) {
    cin >> N;
    cin >> start >> dst;
    
    int eSize;
    cin >> eSize;
    for(int i=0; i<eSize; i++) {
        int v1,v2;

        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    bfs();
}