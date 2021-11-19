#include <bits/stdc++.h>
using namespace std;

int adj[200][200];
int order[1000];
int n,m;

bool bfs(int start, int end) {
    bool visited[n];
    memset(visited, false, n);
    
    queue<int> que;
    que.push(start);
    visited[start] = true;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        if(cur == end)
            return true;
        
        for(int i=0; i<n; ++i) {
            if(adj[cur][i]) {
                if(visited[i])
                    continue;
                else {
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
    }

    return false;
}

int main(void) {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            scanf("%d", &adj[i][j]);
    }

    for(int i=0; i<m; ++i) {
        scanf("%d", &order[i]);
        order[i] -= 1;
    }

    for(int i=0; i<m-1; ++i) {
        if(!bfs(order[i], order[i+1])) {
            printf("NO");
            exit(0);
        }
    }
    printf("YES");
}