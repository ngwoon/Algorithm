#include <bits/stdc++.h>

using namespace std;

/*
    백준 1167번 - 트리의 지름

    백준 1967번과 같은 문제이다.
    다른 점은 어떤 노드가 루트인지 알려주지 않음의 차이가 있다.

    여기서 쓰이는 테크닉 하나가 있는데, 무엇이 루트 노드인지 모르기 때문에 임의의 노드 (항상 1번 노드는 존재하므로 1번 노드로 잡았다.)
    로 dfs 혹은 bfs를 실행하여 가장 먼 노드를 찾고, 해당 노드에서 다시 dfs 혹은 bfs를 돌리면 트리의 지름을 찾을 수 있다.
*/

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> dst;
int V;
int ans=0;

void dfs(int cur, int weightSum) {
    visited[cur]=true;
    bool isLeaf=true;
    for(int i=0; i<adj[cur].size(); i++) {
        int nextNode = adj[cur][i].second;
        if(visited[nextNode]) continue;
        
        isLeaf=false;
        dst[nextNode] = weightSum + adj[cur][i].first;
        dfs(nextNode, dst[nextNode]);
    }
    if(isLeaf) ans = ans < weightSum ? weightSum : ans;
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V;

    adj.resize(V+1);
    visited.resize(V+1,false);
    dst.resize(V+1,0);
    for(int i=1; i<V+1; i++) {
        int node;
        cin >> node;

        while(1) {
            int conn, weight;
            cin >> conn;
            if(conn == -1) break;

            cin >> weight;

            adj[node].push_back({weight, conn});
        }
    }
    
    dfs(1, 0);

    // cout << "ans : " << ans << endl;
    // for(int i=1; i<V+1; i++)
    //     cout << "dst[" << i << "] : " << dst[i] << endl;

    int maxNode=0;
    for(int i=1; i<V+1; i++) {
        if(dst[i] == ans) {
            maxNode = i;
            break;
        }
    }

    fill(visited.begin(), visited.end(), false);
    fill(dst.begin(), dst.end(), 0);
    ans=0;
    dfs(maxNode, 0);

    printf("%d", ans);
}