#include <bits/stdc++.h>
using namespace std;

int dx[2] = {-1,1};

queue<int> que;
vector<int> visited;
int n,k;

void bfs() {
    visited[n] = 0;
    que.push(n);
    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        if(cur == k) 
            continue;
        
        // 걷기
        for(int i=0; i<2; ++i) {
            int next = cur + dx[i];
            if(k < next && i == 1)
                continue;
            if(next < 0 || next > 100000)
                continue;
            if(visited[next] <= visited[cur] + 1)
                continue;

            visited[next] = visited[cur]+1;
            que.push(next);
        }

        if(k < cur)
            continue;
        
        int next = cur * 2;
        if(next < 0 || next > 100000)
            continue;
        if(visited[next] <= visited[cur])   
            continue;
        
        visited[next] = visited[cur];
        que.push(next);
    }
}

int main(void) {
    scanf("%d %d", &n, &k);
    visited.resize(100001, 100001);
    bfs();
    printf("%d", visited[k]);
}