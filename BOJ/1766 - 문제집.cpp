#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
priority_queue<int, vector<int>, greater<int>> pq;
int priority[32001];
int n,m;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    scanf("%d %d", &n, &m);

    adj.resize(n+1);
    for(int i=0; i<m; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        ++priority[b];
        adj[a].push_back(b);
    }

    for(int i=1; i<=n; ++i) {
        if(priority[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        printf("%d ", cur);
        for(int i=0; i<adj[cur].size(); ++i) {
            int next = adj[cur][i];
            if(--priority[next] == 0)
                pq.push(next);
        }
    }
}