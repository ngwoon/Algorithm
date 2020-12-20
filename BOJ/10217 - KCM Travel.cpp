#include <bits/stdc++.h>

/*
    10217번 - KCM Travel

    기본적인 다익스트라 문제인데, "비용" 조건을 추가로 고려해야 하는 문제.

    일반적인 다익스트라는 dst 1차원 배열에 시작점으로부터 각 노드까지의 최단거리를 갱신해 갔다면,

    이 문제는 비용 조건이 있기 때문에 2차원 배열을 사용하여 갱신해야 한다.
    (비용 10을 들여 3번 공항까지 12거리를 간 것과, 비용 9를 들여 3번 공항까지 12 거리를 간 것은 다른 경우의 수이기 때문이다.)
    
    1차원 배열을 사용했을 때, 반례는 아래와 같은 경우가 있을 수 있다.

    만약 10 비용을 들여 3번 공항까지 6거리를 갔다고 하자. 그렇다면 dst[3]은 6이 되어 있을 것이다.
    하지만 그 경로가 뒤에 비용이 커서 n번 공항까지 가지 못하고 queue에서 pop 되어 사라졌다고 가정하자.
    이 상황에서, 5 비용을 들여 3번 공항까지 7거리를 간 경로가 있을 때, 이 경로는 위에서 비용때문에 실패한 경로를 m보다 작거나 같은 비용으로 갈 수 있다고 가정하자.
    하지만 dst[3]=6이고, 이 경로는 현재 7거리를 이동해왔기 때문에, dst[3]은 갱신되지 못한다.
    즉, 거리와 비용을 함께 생각해야 모든 경우의 수를 고려할 수 있다.
*/

#define INF 987654321
using namespace std;

priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> que;
vector<vector<tuple<int,int,int>>> adj;
int dp[102][10002];

int n,m,k;
int u,v,c,d;

void dijkstra() {
    dp[1][0] = 0;
    que.push({0, 1, 0});

    while(!que.empty()) {
        int cur = get<1>(que.top());
        int cost = get<2>(que.top());
        int curDst = get<0>(que.top());
        que.pop();

        if(dp[cur][cost] > curDst) continue;

        for(int i=0; i<adj[cur].size(); ++i) {
            int nn = get<0>(adj[cur][i]);
            int nc = cost + get<1>(adj[cur][i]);
            int nd = curDst + get<2>(adj[cur][i]);

            if(nc > m) continue;
            if(dp[nn][nc] <= nd) continue;
            
            dp[nn][nc] = nd;
            que.push({nd, nn, nc});
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf(" %d %d %d", &n, &m, &k);

        adj.clear();
        adj.resize(n+1);
        
        for(int i=0; i<k; ++i) {
            scanf(" %d %d %d %d", &u, &v, &c, &d);
            adj[u].push_back({v,c,d});
        }

        for(int i=1; i<=n; ++i) fill(dp[i], dp[i] + 10001, INF);

        dijkstra();

        int minDst = INF;
        for(int i=1; i<=m; ++i) {
            if(minDst > dp[n][i]) minDst = dp[n][i];
        }
        if(minDst == INF) printf("Poor KCM\n");
        else printf("%d\n", minDst);
    }
}
