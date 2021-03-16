#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int cur, int target, int cnt) {
    if(cur == target)
        return cnt;
    
    for(int i=0; i<adj[cur].size(); ++i) {
        int next = adj[cur][i];
        if(visited[next])
            continue;
        
        visited[next] = true;
        int res = dfs(next, target, cnt+1);
        visited[next] = false;

        if(res != -1)
            return res;
    }

    return -1;
}

int main(void) {
    int n, m;
    int tc, tp;
    scanf("%d", &n);
    scanf("%d %d", &tc, &tp);

    adj.resize(n+1);
    scanf("%d", &m);
    for(int i=0; i<m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    visited.resize(n+1, false);
    visited[tc] = true;
    printf("%d", dfs(tc, tp, 0));
}