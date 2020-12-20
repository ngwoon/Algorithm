#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
queue<int> que;
int n,m;

void bfs(int start) {
    visited[start] = true;
    que.push(start);

    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        for(int i=0; i<adj[cur].size(); ++i) {
            int next = adj[cur][i];
            if(visited[next])
                continue;
            
            visited[next] = true;
            que.push(next);
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);

    adj.resize(n+1);
    visited.resize(n+1, false); 
    for(int i=0; i<m; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt=0;
    for(int i=1; i<=n; ++i) {
        if(visited[i])
            continue;
        ++cnt; bfs(i);
    }
    printf("%d", cnt);
}