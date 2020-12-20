#include <bits/stdc++.h>
using namespace std;

/*
    3665번 - 최종 순위

    순위를 매기는 문제 : 위상 정렬 문제이다.
    
    문제를 풀며 헷갈렸던 부분이, 우선순위가 바뀐 쌍 (v1, v2)을 잘못 해석하여
    v1, v2로 주어지면 작년엔 v2 -> v1 이었는데 올해 v1 -> v2로 바뀌었다고 해석해서 좀 헤맸다.
    문제에서 주어지는 쌍은 항상 옳으므로, 만약 adj[v1][v2]가 false이면 v1이랑 v2를 바꿔서 adj[v2][v1]를 검사하면 된다.

    그리고 예를들어 1,2,3,4,5위 까지의 관계를 인접행렬로 표현할 때, 예 1->2->3->4->5 이렇게만 연결하는게 아니라
    1->2, 1->3, 1->4, 1->5, 2->3, 2->4.... 이런식으로 모든 관계를 다 설정해 주어야 문제에서 주어진 쌍의 관계를 변경했을 때
    나머지 순위간의 위상이 변질되지 않는다.
*/

int t,n,m;

int main(void) {
    scanf("%d", &t);
    for(int k=0; k<t; ++k) {
        scanf(" %d", &n);
        
        queue<int> que;
        vector<int> indegree;
        vector<int> result;
        vector<vector<bool>> adj;
        string ans="ANS";
        
        int ly[n];
        for(int i=0; i<n; ++i) scanf(" %d", &ly[i]);

        indegree.resize(n+1,0);
        adj.resize(n+1);
        for(int i=1; i<=n; ++i) adj[i].resize(n+1, false);
        
        for(int i=0; i<n-1; ++i) {
            for(int j=i+1; j<n; ++j) {
                adj[ly[i]][ly[j]]=true;
                ++indegree[ly[j]];
            }
        }

        scanf(" %d", &m);
        for(int i=0; i<m; ++i) {
            int v1, v2;
            scanf(" %d %d", &v1, &v2);
            if(!adj[v2][v1]) { v1 ^= v2; v2 ^= v1; v1 ^= v2; }
            adj[v2][v1]=false; adj[v1][v2]=true; --indegree[v1]; ++indegree[v2];
        }

        for(int i=1; i<=n; ++i) {
            if(indegree[i] == 0) que.push(i);
        }

        while(!que.empty()) {
            if(que.size() > 1) { ans="?"; break; }

            int cur = que.front();
            que.pop();

            result.push_back(cur);
            for(int i=1; i<=n; ++i) {
                if(adj[cur][i]) {
                    if(--indegree[i] == 0) que.push(i);
                }
            }
        }

        if(ans != "ANS") printf("%s\n", ans.c_str());
        else {
            if(result.size() == n) {
                for(int i=0; i<n; ++i) printf("%d ", result[i]);
            } 
            else printf("IMPOSSIBLE");
            
            printf("\n");
        }
    }
}