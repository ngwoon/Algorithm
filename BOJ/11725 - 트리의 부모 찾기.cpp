#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> parentArr;

void dfs(int cur, int parent) {
    if(parent != -1)
        parentArr[cur] = parent;
    
    for(int i=0; i<tree[cur].size(); ++i) {
        int child = tree[cur][i];
        if(visited[child])
            continue;

        visited[child] = true;
        dfs(child, cur);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    tree.resize(n+1);
    visited.resize(n+1,false);
    parentArr.resize(n+1);
    for(int i=0; i<n-1; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1);

    for(int i=2; i<=n; ++i)
        printf("%d\n", parentArr[i]);
}