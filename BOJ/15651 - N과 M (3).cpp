#include <bits/stdc++.h>
using namespace std;

/*
    15649 - N과 M (3)

    
*/

int n,m;
vector<int> seq;

void dfs(int count) {
    if(count == m) {
        for(int num : seq)
            printf("%d ", num);
        printf("\n");
        return;
    }

    for(int i=1; i<=n; ++i) {
        seq.push_back(i);
        dfs(count + 1);
        seq.erase(seq.end() - 1);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    dfs(0);
}