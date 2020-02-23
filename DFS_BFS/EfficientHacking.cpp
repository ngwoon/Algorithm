#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> adj[10001];
vector<int> answer;
queue<int> que;
vector<bool> visited;
void bfs(int start) {
    visited[start] = true;
    que.push(start);

    int cnt = 0;
    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        int len = adj[cur].size();
        for(int i=0; i<len; i++) {
            int nc = adj[cur][i];
            if(visited[nc])
                continue;
            
            ++cnt;
            visited[nc] = true;
            que.push(nc);
        }
    }
    answer.push_back(cnt);
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n2].push_back(n1);
    }

    for(int i=0; i<N + 1; i++)
        visited.push_back(false);

    for(int i=1; i<N + 1; i++) {
        bfs(i);
        for(int j=0; j<N + 1; j++)
            visited[j] = false;
    }
    int maxVal = 0;
    string result;
    for(int i=0; i<N; i++) {
        if(maxVal < answer[i]) {
            maxVal = answer[i];
            result.clear();
            result.append(to_string(i + 1)).append(" ");
        } else if(maxVal == answer[i])
            result.append(to_string(i + 1)).append(" ");
    }
    cout << result;
}