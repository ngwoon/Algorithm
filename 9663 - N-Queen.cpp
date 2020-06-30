#include <bits/stdc++.h>
using namespace std;

/*
    9663 - N-Queen
    
    백트래킹의 대표적인 문제.

    퀸을 하나 둘 때마다 둘 수 없게되는 좌표를 누적 표기하여 풀었다.
*/

int field[16][16];
int ans, n;

bool check(int y, int x) {
    // 열 검사
    for(int i=1; i<=n; ++i)
        if(field[i][x]) return false;

    // 대각 검사
    int i=y-1, j=x-1;
    while(i >= 1 && j >= 1) {
        if(field[i--][j--]) return false;
    }
    i=y+1; j=x+1;
    while(i <= n && j <= n) {
        if(field[i++][j++]) return false;
    }
    i=y+1; j=x-1;
    while(i <= n && j >= 1) {
        if(field[i++][j--]) return false;
    }
    i=y-1; j=x+1;
    while(i >= 1 && j <= n) {
        if(field[i--][j++]) return false;
    }
    
    return true;
}

void block(int y, int x, int flag) {
    // 열 block, unblock
    for(int i=1; i<=n; ++i)
        field[i][x] += flag;

    // 대각 block, unblock
    int i=y-1, j=x-1;
    while(i >= 1 && j >= 1)
        field[i--][j--] += flag;
    
    i=y+1; j=x+1;
    while(i <= n && j <= n)
        field[i++][j++] += flag;
    
    i=y+1; j=x-1;
    while(i <= n && j >= 1)
        field[i++][j--] += flag;

    i=y-1; j=x+1;
    while(i >= 1 && j <= n)
        field[i--][j++] += flag;
}   

void dfs(int y) {
    if(y == n+1) { ++ans; return; }

    for(int x=1; x<=n; ++x) {
        if(field[y][x] > 0) continue;
        block(y, x, 1);
        dfs(y+1);
        block(y, x, -1);
    }
}

int main(void) {
    scanf("%d", &n);
    dfs(1);
    printf("%d", ans);
}