#include <bits/stdc++.h>
using namespace std;

int dx[2] = {-1,1};

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
vector<bool> visited;
int n,k;

int bfs() {
    visited[n] = true;
    que.push({0, n});
    while(!que.empty()) {
        int cnt = que.top().first;
        int cur = que.top().second;

        printf("cur : %d, cnt : %d\n", cur, cnt);

        que.pop();

        if(cur == k)
            return cnt;
        
        // 걷기
        for(int i=0; i<2; ++i) {
            int next = cur + dx[i];

            if(next < 0 || next > 100000)
                continue;
            if(visited[next])
                continue;

            visited[next] = true;
            que.push({cnt+1, next});
        }

        int next = cur * 2;
        if(next < 0 || next > 100000)
            continue;
        if(visited[next])   
            continue;
        
        visited[next] = true;
        que.push({cnt, next});
    }
}

int main(void) {
    scanf("%d %d", &n, &k);
    visited.resize(100001, false);
    printf("%d", bfs());
}