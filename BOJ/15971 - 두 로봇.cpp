#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

queue<pair<int, int>> que;
vector<pair<int, int>> adj[100001];
vector<int> dist;
vector<int> path;
int n, start, dest;

void bfs() {
    que.push({start, 0});
    dist[start] = 0;

    while(!que.empty()) {
        int pos = que.front().first;
        int curDist = que.front().second;
        que.pop();

        if(pos == dest)
            continue;

        for(int i=0; i<adj[pos].size(); ++i) {
            int next = adj[pos][i].first;
            int ndist = curDist + adj[pos][i].second;
            if(dist[next] <= ndist) continue;
            
            dist[next] = ndist;
            path[next] = pos;
            que.push({next, ndist});
        }
    }
}

int main(void) {
    scanf("%d %d %d", &n, &start, &dest);

    dist.resize(n+1, INF);
    path.resize(n+1, -1);

    for(int i=0; i<n-1; ++i) {
        int c1, c2, cost;
        scanf("%d %d %d", &c1, &c2, &cost);
        adj[c1].push_back({c2, cost});
        adj[c2].push_back({c1, cost});
    }

    bfs();

    vector<int> pathCost;
    int after = dest;
    while(path[after] != -1) {
        int before = path[after];
        for(int i=0; i<adj[before].size(); ++i) {
            if(adj[before][i].first == after) {
                pathCost.push_back(adj[before][i].second);
                break;
            }
        }
        after = before;
    }

    sort(pathCost.begin(), pathCost.end());

    int sum=0, len=pathCost.size();
    for(int i=0; i<len-1; ++i)
        sum += pathCost[i];
    
    printf("%d", sum);
}