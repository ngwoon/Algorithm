#include <bits/stdc++.h>
using namespace std;

/*
    11657번 - 타임머신

    음수 가중치가 존재할 수 있으므로, 벨만 - 포드 알고리즘을 사용하여 거리를 측정해야 한다.

    발생할 수 있는 예외는 크게 2가지가 있었다.
    1. A와 B가 서로 -10000 가중치로 이어져 있는 경우
    이 경우, dst배열 자료형을 int로 하게되면 마지막 edge relaxation 중에 음수 -> 양수로의 overflow가 발생할 수 있다.
    마지막 edge relaxation은 업데이트가 발생하면 음의 가중치 사이클이 있다고 판단하는데, 음 -> 양으로 overflow가 발생하면
    거리가 늘어난 것으로 판단하여 음의 가중치 사이클을 잡아내지 못한다.

    2. 음의 가중치 사이클이 존재하지만, 도시1 에서 해당 사이클까지 경로가 없는 경우
    이 경우 문제 조건에 의해 -1만 출력하는 것이 아니라 경로가 없는 도시를 -1로 출력해야 한다.
*/


#define INF 987654321

int n,m;
vector<vector<pair<int, int>>> adj;
vector<long long> dst;
bool imp;

void bellmanFord() {
    // edge relaxation n-1회 + 음수 가중치 사이클 확인 차 추가 1회
    for(int i=1; i<=n; ++i) {
        // edge relaxation 수행 시 모든 edge에 대해 수행
        for(int j=1; j<=n; ++j) {
            for(int k=0; k<adj[j].size(); ++k) {
                if(dst[j] == INF) continue;
                if(dst[adj[j][k].second] > dst[j] + adj[j][k].first) {
                    if(i == n) {
                        imp = true;
                        return;
                    }
                    else
                        dst[adj[j][k].second] = dst[j] + adj[j][k].first;
                }
            }
        }
    }
}

int main(void) {
    scanf(" %d %d", &n, &m);

    adj.resize(n+1);
    for(int i=0; i<m; ++i) {
        int s, e, w;
        scanf(" %d %d %d", &s, &e, &w);
        adj[s].push_back({w,e});
    }

    dst.resize(n+1, INF);
    dst[1] = 0;
    bellmanFord();

    if(imp) printf("-1");
    else {
        for(int i=2; i<=n; ++i)
            printf("%lld\n", dst[i] == INF ? -1 : dst[i]);
    }
}