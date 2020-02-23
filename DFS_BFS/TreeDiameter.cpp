#include <bits/stdc++.h>

#define INF 150

using namespace std;

vector<pair<int, int>> adj[10001];
queue<pair<int,int>> que;
vector<int> answer;
bool visited[10001];
int N;

int bfs(int start) {
    que.push({0, start});
    visited[start] = true;

    int maxDst = 0;
    while(!que.empty()) {
        int cur = que.front().second;
        int w = que.front().first;
        que.pop();

        int len = adj[cur].size();
        for(int i=0; i<len; i++) {
            int nc = adj[cur][i].second;
            int nw = adj[cur][i].first;

            if(visited[nc])
                continue;
            
            maxDst = (maxDst < w + nw) ? w + nw : maxDst;
            visited[nc] = true;
            que.push({w + nw, nc});
        }
    }

    return maxDst;
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=1; i<N; i++)  {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        adj[n1].push_back({w, n2});
        adj[n2].push_back({w, n1});
    }

    for(int i=1; i<N + 1; i++) {
        answer.push_back(bfs(i));
        memset(visited, false, N + 1);
    }

    int maxVal = 0;
    for(int i=1; i<N + 1; i++)
        maxVal = maxVal < answer[i] ? answer[i] : maxVal;
    
    cout << maxVal;
}