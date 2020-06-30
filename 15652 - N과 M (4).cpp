#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> seq;

void dfs(int index, int count) {
    if(count == m) {
        for(int num : seq)
            printf("%d ", num);
        printf("\n");
        return;
    }

    for(int i=index; i<=n; ++i) {
        seq.push_back(i);
        dfs(i, count + 1);
        seq.erase(seq.end() - 1);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    dfs(1, 0);
}