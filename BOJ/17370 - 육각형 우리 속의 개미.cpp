#include <bits/stdc++.h>
using namespace std;

/*
    17370번 - 육각형 우리 속의 개미

    문제만 읽어봤을 땐, 기하 알고리즘 쪽 인듯 하여 한참을 헤맸는데 시간을 들여 생각해보니
    꼭짓점을 노드로 삼는 그래프 문제였다.
    육각형 변을 따라 움직이는 형태로 dfs를 돌려 회전한 숫자가 n과 같으면 정답을 1만큼 올려주면 된다.

    어느 꼭짓점에서 갈 수 있는 방향은 3가지가 있는데, 해당 위치를 몇 개의 변을 거쳐서 왔는지에 따라 또 다르다.
    즉, 총 6가지의 갈 수 있는 방위가 존재하며, 짝수, 홀수 번 째마다 그 방위가 다르다.
*/

int dx[2][3] = {{-1,0,1},{-1,0,1}};
int dy[2][3] = {{-1,1,-1},{1,-1,1}};

bool visited[101][101];
int n,ans;

void dfs(int by, int bx, int y, int x, int cnt) {
    if(cnt == n) return;

    visited[y][x]=true;
    for(int i=0; i<3; ++i) {
        int ny = y + dy[cnt%2][i];
        int nx = x + dx[cnt%2][i];
        int ncnt = cnt + 1;

        if(by == ny && bx == nx) continue;
        if(visited[ny][nx]) {
            if(ncnt == n) ++ans;
            continue;
        }

        dfs(y, x, ny, nx, ncnt);
        visited[ny][nx]=false;
    }
}

int main(void) {
    scanf("%d", &n);

    memset(visited,false,sizeof(visited));
    
    visited[51][50]=true;
    dfs(51,50,50,50,0);

    printf("%d", ans);
}