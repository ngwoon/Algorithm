#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
vector<vector<pair<int, int>>> adj;
vector<int> dst;
vector<int> path;
int n,m;
int start, dest;

void dijkstra() {
    que.push({0, start});
    dst[start] = 0;
    path[start] = -1;

    while(!que.empty()) {
        int cur = que.top().second;
        int curDst = que.top().first;
        que.pop();

        if(dst[cur] < curDst) continue;

        for(int i=0; i<adj[cur].size(); ++i) {
            int nc = adj[cur][i].second;
            int ndst = adj[cur][i].first + curDst;

            if(dst[nc] <= ndst) continue;

            path[nc] = cur;
            dst[nc] = ndst;
            que.push({ndst, nc});
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);

    adj.resize(n+1);
    for(int i=0; i<m; ++i) {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);
        adj[v1].push_back({w,v2});
    }

    scanf(" %d %d", &start, &dest);

    dst.resize(n+1, INF);
    path.resize(n+1, 0);
    
    dijkstra();

    printf("%d\n", dst[dest]);
    deque<int> deq;
    int index = dest;
    while(index != -1) { deq.push_front(index); index = path[index]; }

    printf("%d\n", deq.size());
    for(int i=0; i<deq.size(); ++i) printf("%d ", deq[i]);
}