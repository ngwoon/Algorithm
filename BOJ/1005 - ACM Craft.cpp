#include <bits/stdc++.h>
using namespace std;

vector<int> res;
int n,k;

int main(void) {
    int t;

    scanf("%d", &t);
    for(int z=0; z<t; ++z) {
        scanf(" %d %d", &n, &k);

        queue<int> que;
        vector<vector<int>> adj;
        vector<int> indegree;
        vector<int> sec;
        vector<int> dest;

        sec.resize(n+1);
        indegree.resize(n+1);
        adj.resize(n+1);
        dest.resize(n+1);

        for(int i=1; i<=n; ++i) scanf(" %d", &sec[i]);
        for(int i=0; i<k; ++i) {
            int v1, v2;
            scanf(" %d %d", &v1, &v2);
            adj[v1].push_back(v2);
            ++indegree[v2];
        }

        int target;
        scanf(" %d", &target);
        
        for(int i=1; i<=n; ++i) {
            if(indegree[i] == 0) que.push(i);
        }

        for(int i=0; i<n; ++i) {
            int cur = que.front();
            que.pop();

            if(cur == target) break;

            for(int j=0; j<adj[cur].size(); ++j) {
                int nc = adj[cur][j];
                if(dest[nc] < dest[cur] + sec[cur]) dest[nc] = dest[cur] + sec[cur];
                if(--indegree[nc] == 0) que.push(nc);
            }
        }

        res.push_back(dest[target] + sec[target]);
    }

    for(int i=0; i<res.size(); ++i) printf("%d\n", res[i]);
}