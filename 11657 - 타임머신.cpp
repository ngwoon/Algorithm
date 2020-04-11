#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dst;
int n,m;
bool imp;

void bellmanFord() {
    dst[1] = 0;
    for(int i=1; i<=n; ++i) {
        for(int from=1; from<=n; ++from) {
            for(auto& edge : adj[from]) {
                int to = edge.first;
                int weight = edge.second;

                if(dst[from] == INF) continue;

                if(dst[from] + weight < dst[to]) {
                    dst[to] = dst[from] + weight;
                    if(i == n) imp = true;
                }
            }
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);

    adj.resize(n+1);
    for(int i=0; i<m; ++i) {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);

        adj[v1].push_back({v2,w});
    }
    
    dst.resize(n+1,INF);
    
    bellmanFord();

    if(imp) printf("-1");
    else {
        for(int i=2; i<=n; ++i)
            printf("%d\n", dst[i] == INF ? -1 : dst[i]);
    }
}