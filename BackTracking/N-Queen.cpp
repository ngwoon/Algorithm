#include <bits/stdc++.h>
using namespace std;

int pos[15] = {-1};
int ans=0;
int N;

// 대각 확인
bool check(int level) {
    for(int i=0; i<level; i++) {
        if(abs(level - i) == abs(pos[level] - pos[i])) return false;
    }
    return true;
}
void dfs(int level, int queen) {
    
    if(queen == 0) {
        ++ans;
        return;
    }

    for(int j=0; j<N; j++) {
        int i;
        for(i=0; i<level; i++) {
            if(pos[i] == j) break;
        }
        if(i != level) continue;

        pos[level] = j;
        if(!check(level)) continue;

        dfs(level+1, queen-1);
        pos[level]=-1; // 필요없나?
    }
}

int main(void) {
    scanf("%d", &N);
    dfs(0, N);
    printf("%d", ans);
}
