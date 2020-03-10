#include <cstdio>
#include <vector>
using namespace std;

/*
    17489번 - 보물 찾기

    사이클인지 아닌지를 판단하는 방법을 생각해내는 문제

    사이클은 어떤 경로가 자신이 이미 거쳐온 곳을 다시 거쳐가면서 발생한다.
    처음엔 bfs를 이용했는데, 이 경우 다양한 경로가 동시에 발생하면서 사이클을 판단하기 어려웠다.

    그래서 백트래킹을 이용한 dfs로 자기 자신이 거쳐온 좌표에 다시 갈 수 있게 될 때, 사이클이라 판단하고 -1를 출력하게끔 했다.

    플레4 라기엔 조금 쉬운 문제
*/

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

char map[101][101];
vector<vector<bool>> visited;
char str[27];
int N,M,K;
int ans=0;
int ay, ax;
bool poss=true;

void dfs(int cnt, int cur, int y, int x) {

    if(ans < cnt) { ans = cnt; ay = y; ax = x; }

    for(int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
        if(map[ny][nx] != str[cur]) continue;

        if(visited[ny][nx]) { poss=false; return; }

        int nextChar = cur + 1;
        int ncnt = cnt;
        if(str[nextChar] == '\0') { nextChar=0; ++ncnt; }

        visited[ny][nx]=true;
        dfs(ncnt, nextChar, ny, nx);
        if(!poss) return;
        visited[ny][nx]=false;
    }
}

int main(void) {
    scanf("%d %d %d", &N, &M, &K);
    scanf("%s", str);

    visited.resize(N+1);
    for(int i=1; i<N+1; ++i) visited[i].resize(M+1,false);

    for(int i=1; i<N+1; ++i)
        for(int j=1; j<M+1; ++j)
            scanf(" %c", &map[i][j]);
    
    if(str[1] != '\0') dfs(0,1,1,1);
    else poss=false;

    if(!poss || ans == 0) printf("-1");
    else printf("%d\n%d %d", ans, ay, ax);
}