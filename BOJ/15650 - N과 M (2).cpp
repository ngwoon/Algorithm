#include <bits/stdc++.h>
using namespace std;

/*
    15649 - N과 M (2)

    N과 M (1) 에서 추가된 조건
    수열은 오름차순이어야 하며, 이미 출력한 수열을 출력하면 안된다.

    N과 M (1) 에서는 m개의 요소를 갖는 가능한 모든 수열을 출력했다면, (2) 에서는 오름차순 수열 중 요소가 중복되지 않거나
    수열 자체가 중복되지 않게끔 출력해야 한다.
*/

int n,m;
vector<int> seq;
bool used[9];

void dfs(int index, int count) {
    if(count == m) {
        for(int num : seq)
            printf("%d ", num);
        printf("\n");
        return;
    }

    for(int i=index; i<=n; ++i) {
        if(used[i]) continue;
        
        seq.push_back(i);
        used[i] = true;
        dfs(i + 1, count + 1);
        used[i] = false;
        seq.erase(seq.end() - 1);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    dfs(1, 0);
}