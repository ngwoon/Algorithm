#include <bits/stdc++.h>
using namespace std;

/*
    15649 - N과 M (1)

    백트래킹 기초.
    dfs 함수는 기저 조건을 확인하는 부분과 다음으로 넣을 수를 찾는 부분으로 나뉘어진다.
*/

int n,m;
vector<int> seq;
bool used[9];

void dfs(int count) {
    if(count == m) {
        for(int num : seq)
            printf("%d ", num);
        printf("\n");
        return;
    }

    for(int i=1; i<=n; ++i) {
        if(used[i]) continue;
        
        seq.push_back(i);
        used[i] = true;
        dfs(count + 1);
        used[i] = false;
        seq.erase(seq.end() - 1);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    dfs(0);
}