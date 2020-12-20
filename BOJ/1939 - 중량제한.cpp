#include <bits/stdc++.h>
using namespace std;

/*
    1939번 - 중량제한

    bfs와 이분탐색을 함께 사용한 문제
    n의 최대 크기가 100000 이므로 일반적인 bfs로 풀면 시간초과가 난다.
    또한, 도착점까지 가장 빠르게 가는 문제가 아니라 최대 중량을 찾는 문제이므로 색다른 접근법이 필요했다.

    아울러 두 섬 간에 여러 다리가 존재할 수 있으므로, 나의 경우 인접리스트를 다리 가중치의 내림차순으로 정렬하여
    다른 섬으로 이동할 때 항상 최대 중량의 다리로 지나가게끔 했다. 
*/

queue<int> que;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
int n,m;
int start, dest;
int ans=0;

bool bfs(int highWeight) {
    que.push(start);
    visited[start]=true;

    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        if(cur == dest) { while(!que.empty()) que.pop(); return true; }

        for(int i=0; i<adj[cur].size(); ++i) {
            int nc = adj[cur][i].second;
            if(visited[nc]) continue;
            if(highWeight > adj[cur][i].first) continue;

            visited[nc]=true;
            que.push(nc);
        }
    }

    return false;
}

int main(void) {
    scanf("%d %d", &n, &m);

    adj.resize(n+1);
    visited.resize(n+1, false);
    for(int i=0; i<m; ++i) {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);
        
        adj[v1].push_back({w, v2});
        adj[v2].push_back({w, v1});
    }

    for(int i=1; i<=n; ++i) sort(adj[i].begin(), adj[i].end(), greater<pair<int, int>>());
    
    scanf(" %d %d", &start, &dest);

    int low=1, high=1000000000;
    while(low<=high) {
        int mid = (low + high)/2;
        if(bfs(mid)) { low = mid + 1; ans = mid; }
        else high = mid-1;
        fill(visited.begin(), visited.end(), false);
    }

    printf("%d", ans);
}