#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> adj[101];
vector<bool> answer[101];
vector<bool> visited;

queue<int> que;

int N;

void bfs(int start) {
    
    que.push(start);

    while(!que.empty()) {
        int cur = que.front();

        que.pop();
        
        // 현재 노드에서 갈 수 있는 노드 탐색
        for(int i=0; i<N; i++) {
            // 이미 방문한 노드이거나 갈 수 없는 노드이면 pass
            if(visited[i] || !adj[cur][i])
                continue;

            answer[start][i] = true;

            visited[i] = true;

            que.push(i + 1);
        }
    }
}

int main(void) {

    cin >> N;

    for(int i=1; i<N + 1; i++) {
        for(int j=0; j<N; j++) {
            int temp;
            cin >> temp;

            adj[i].push_back(temp == 1 ? true : false);
            answer[i].push_back(false);
        }
        visited.push_back(false);
    }

    // 각 노드마다 bfs실행
    for(int i=1; i<N + 1; i++) {
        bfs(i);

        for(int j=0; j<N; j++)
            visited[j] = false;
    }

    for(int i=1; i<N + 1; i++) {
        for(int j=0; j<N; j++)
            cout << answer[i][j] << " ";
        cout << "\n";
    }
}