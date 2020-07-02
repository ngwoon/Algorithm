#include <bits/stdc++.h>
using namespace std;

/*
    16397번 - 탈출
    
    기본적인 bfs 문제. 문제에서 주어진 조건만 잘 걸러주면 된다.
*/

queue<pair<int, int>> que;
vector<bool> visited;
int n,t,g;

void bfs() {
    que.push({n,0});
    visited[n]=true;

    while(!que.empty()) {
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if(cur == g) { printf("%d", cnt); exit(0); }
        if(t == cnt) continue;

        // A버튼
        int nc = cur+1;
        int ncnt = cnt+1;
        if(nc > 99999) goto B;
        if(visited[nc]) goto B;

        visited[nc]=true;
        que.push({nc, ncnt});

    B:
        // B버튼
        nc = cur * 2;
        if(nc > 99999) continue;
        string temp = to_string(nc);
        temp[0] -= 1;
        nc = atoi(temp.c_str());

        if(visited[nc]) continue;

        visited[nc]=true;
        que.push({nc, ncnt});
    }
}

int main(void) {
    scanf("%d %d %d", &n, &t, &g);

    visited.resize(100000,false);
    bfs();
    printf("ANG");
}