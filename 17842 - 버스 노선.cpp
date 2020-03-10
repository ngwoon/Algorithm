#include <bits/stdc++.h>
using namespace std;

/*
    17842번 - 버스 노선

    버스 노선을 최소화 하기 위해선, 연결된 정류장이 2개 이상인 정류장을 루트로 하는 트리를 생각하면 된다.
    위의 조건을 만족시키면, (leaf노드의 갯수 + 1) / 2가 답이된다.
    단, 연결된 정류장이 2개 이상인 노드가 하나도 없을 수 있는데, 이땐 노선 하나로 모든 정류장을 지나칠 수 있으므로
    1을 답으로 출력하면 된다.
*/

vector<vector<int>> adj;
int N,ans;

int main(void) {
    scanf("%d", &N);

    adj.resize(N);
    for(int i=0; i<N-1; ++i) {
        int v1, v2;
        scanf(" %d %d", &v1, &v2);
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    int start=-1;
    for(int i=0; i<N; ++i) {
        if(adj[i].size() >= 2) start=i;
        else if(adj[i].size() == 1) ++ans;
    }
    if(start == -1) ans=1;

    printf("%d", (ans+1)/2);
}