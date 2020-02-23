#include <stdio.h>
#include <vector>
using namespace std;

/*
    백트래킹을 이용한 경로 탐색
    백준 1987번 - 알파벳
*/

// 상하좌우 이동
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

vector<char> route;     // 경로 상의 알파벳 저장 (알파벳 중복 방지)
char board[20][20];     // 맵
bool visited[20][20];   // 이미 거쳐간 곳을 또 거쳐가는 것을 방지
int R,C;
int ans=1;              // 경로들 중 최대 알파벳 수 저장

void dfs(int y, int x) {
    visited[y][x] = true;
    route.push_back(board[y][x]);

    if(ans < route.size())
        ans = route.size();

    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
        
        int j;
        for(j=0; j<route.size(); j++) {
            if(board[ny][nx] == route[j]) 
                break;
        }
        if(j != route.size()) continue;
        
        // 백트래킹의 핵심
        // 해당 경로 탐색 완료 후에 visited배열과 저장했던 알파벳을 이전으로 되돌린다.
        dfs(ny, nx);
        visited[ny][nx] = false;
        route.erase(route.end() - 1);
    }
}

int main(void) {
    scanf("%d %d", &R, &C);

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            scanf(" %c", &board[i][j]);
    
    dfs(0,0);
    printf("%d", ans);
}