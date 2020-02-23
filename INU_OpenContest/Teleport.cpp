#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[300001];

int N, M, S, E;

queue<pair<int, int>> que;
bool visited[300001];

void bfs() {
    que.push({S, 0});

    visited[S] = true;

    while(!que.empty()) {
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if(cur == E) {
            cout << cnt;
            exit(0);
        }

        for(int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i];

            if(visited[next])
                continue;
            
            visited[next] = true;
            
            que.push({next, cnt + 1});
        }
    }
}

int main(void) {
    cin >> N >> M >> S >> E;

    // 그래프 초기화
    for(int i=1; i<N; i++) {
        adj[i].push_back(i + 1);
        adj[i + 1].push_back(i);
    }

    for(int i=0; i<M; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    bfs();
}