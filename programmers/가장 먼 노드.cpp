#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int bfs(int n) {
    int answer=0;
    int maxDst=0;

    queue<pair<int, int>> que;
    que.push({1, 0});
    visited[1] = true;

    while(!que.empty()) {
        int cur = que.front().first;
        int dst = que.front().second;
        que.pop();

        if(dst > maxDst) {
            maxDst = dst;
            answer = 1;
        } else if(dst == maxDst)
            ++answer;

        for(int i=0; i<adj[cur].size(); ++i) {
            int next = adj[cur][i];
            if(visited[next])
                continue;

            visited[next] = true;
            que.push({next, dst + 1});
        }
    }

    return answer;
}

int solution(int n, vector<vector<int>> edge) {
    adj.resize(n+1);
    for(int i=0; i<edge.size(); ++i) {
        vector<int> cur = edge[i];
        adj[cur[0]].push_back(cur[1]);
        adj[cur[1]].push_back(cur[0]);
    }

    visited.resize(n+1, false);
    

    return bfs(n);
}