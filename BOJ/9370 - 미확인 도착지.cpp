#include <bits/stdc++.h>
#define INF 987654321

/*
    9370번 - 미확인 도착지

    반드시 거쳐가야 하는 간선이 주어지고, 시작점부터 목적지까지 해당 간선을 거쳐 갈 수 있는지 묻는 문제.

    나는 다익스트라를 3번 사용하여 풀었는데, 인터넷에 검색해보니 2번 사용하여 푸는 방법도 있었다.

    우선 내가 푼 방식은, 시작점을 s, 거처가는 간선은 g->h 혹은 h->g이다.

    목적지를 t라 했을 때, s->g->h->t 혹은 s->h->g->t 라는 경로가 가능하다. (물론 t 이전에 반드시 g 혹은 h라는 보장은 없다.)

    간단하게 생각해보면, g->h 거리는 입력으로 주어지고, s->g 혹은 s->h 는 s를 시작점으로 하는 다익스트라로 구할 수 있고,
    h -> t거리가 가까운지, g -> t 거리가 가까운지는 각각 h,g를 시작점으로 하는 다익스트라로 구할 수 있다.

    따라서 다익스트라를 3번 사용하여 거리 비교를 통해 정답을 구할 수 있다.


    다익스트라를 2번 사용하는 방법은 아래와 같다.

    S에서 T로 가는 최단 경로에 GH 간선이 포함되어 있다고 가정해보자.
    다익스트라 알고리즘은 각 상황에서 최단 간선을 선택하여 동작하는 그리디 알고리즘이다.
    즉, S->G와 S->H 중 짧은 간선을 선택하게 된다.
    만약 위에서 S->G가 선택되었다면, G->H는 입력으로 주어지므로, H->T만 알면 S->T와 비교할 수 있다.
    즉, dijkstra(S) 와 dijkstra(min(S->G,S->H)) 이렇게 2번의 다익스트라로 정답을 구할 수 있다.
*/

using namespace std;

priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> que;
vector<vector<pair<int,int>>> adj;
vector<int> dst;
int s,g,h;

void dijkstra(int start) {
    dst[start] = 0;
    que.push({0, start});

    while(!que.empty()) {
        int cur = que.top().second;
        int curDst = que.top().first;
        que.pop();

        if(dst[cur] < curDst) continue;

        for(int i=0; i<adj[cur].size(); ++i) {
            int nc = adj[cur][i].first;
            int ndst = curDst + adj[cur][i].second;

            if(ndst >= dst[nc]) continue;

            dst[nc] = ndst;
            que.push({ndst,nc});
        }
    }
}

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        int n,m,t;

        int gToh;

        scanf(" %d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);

        adj.clear();
        adj.resize(n+1);
        for(int i=0; i<m; ++i) {
            int a,b,w;
            scanf(" %d %d %d", &a, &b, &w);
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
            if((a == g && b == h) || (a == h && b == g)) gToh = w;
        }

        vector<bool> isCandidate;
        isCandidate.resize(n+1,false);
        for(int i=0; i<t; ++i) {
            int temp;
            scanf(" %d", &temp);
            isCandidate[temp] = true;
        }

        dst.clear();
        dst.resize(n+1, INF);
        dijkstra(g);

        vector<int> gdst;
        gdst.resize(n+1);
        for(int i=1; i<=n; ++i) gdst[i] = dst[i];

        dst.clear();
        dst.resize(n+1, INF);
        dijkstra(h);

        vector<int> hdst;
        hdst.resize(n+1);
        for(int i=1; i<=n; ++i) hdst[i] = dst[i];

        vector<int> shortDst;
        shortDst.resize(n+1);
        for(int i=1; i<=n; ++i) {
            shortDst[i] = min(gdst[s] + hdst[i], hdst[s] + gdst[i]) + gToh;
        }
        
        dst.clear();
        dst.resize(n+1, INF);
        dijkstra(s);

        for(int i=1; i<=n; ++i) {
            if(isCandidate[i] && shortDst[i] <= dst[i]) printf("%d ", i);
        }
        printf("\n");
    }
}