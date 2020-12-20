#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n;
int sum;

void dfs(int cur, int depth) {
    bool isLeaf = true;
    visited[cur] = true;
    
    for(int i=0; i<adj[cur].size(); ++i) {
        int nextNode = adj[cur][i];

        if(visited[nextNode]) continue;

        isLeaf = false;
        dfs(nextNode, depth + 1);
    }

    if(isLeaf) sum += depth;
}

int main(void) {
    scanf("%d", &n);

    adj.resize(n+1);
    for(int i=0; i<n-1; ++i) {
        int n1, n2;
        scanf(" %d %d", &n1, &n2);
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    visited.resize(n+1, false);
    dfs(1, 0);

    if(sum % 2 == 0) printf("No");
    else printf("Yes");
}