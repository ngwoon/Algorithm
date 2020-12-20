#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
vector<int> times;
vector<int> result;
queue<int> que; 
int N;

int main(void) {
    scanf("%d", &N);

    indegree.resize(N+1,0);
    result.resize(N+1,0);
    times.resize(N+1);
    adj.resize(N+1);
    for(int i=1; i<=N; ++i) {
        scanf(" %d", &times[i]);
        
        while(1) {
            int b;
            scanf(" %d", &b);
            if(b == -1) break;

            adj[b].push_back(i);
            ++indegree[i];
        }
    }

    for(int i=1; i<=N; ++i) { if(indegree[i] == 0) que.push(i); }
    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        for(int i=0; i<adj[cur].size(); ++i) {
            int nc = adj[cur][i];
            if(--indegree[nc] == 0) que.push(nc); 
            result[nc] = max(result[nc], result[cur] + times[cur]);
        }
    }

    for(int i=1; i<=N; ++i) printf("%d\n", result[i] + times[i]);
}