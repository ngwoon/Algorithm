#include <bits/stdc++.h>
#define END_POS 100000
using namespace std;

int dx[2] = {-1,1};

queue<pair<int, int>> que; 
int subin, bro;
int field[100001];
vector<bool> visited;


void bfs() {
    visited[subin]=true;
    que.push({subin, 0});

    while(!que.empty()) {
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if(cur == bro) {
            printf("%d", cnt);
            exit(0);
        }

        for(int i=0; i<2; ++i) {
            int npos = cur + dx[i];
            
            if(npos < 0 || npos > END_POS) continue;
            if(visited[npos]) continue;

            visited[npos] = true;
            que.push({npos, cnt + 1});
        }

        int npos = (cur<<1);
        if(npos > END_POS) continue;
        if(visited[npos]) continue;

        visited[npos] = true;
        que.push({npos, cnt + 1});
    }
}

int main(void) {
    scanf("%d %d", &subin, &bro);

    if(bro < subin) { printf("%d", subin - bro); exit(0); }

    visited.resize(100001,false);
    bfs();
}