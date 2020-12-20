#include <bits/stdc++.h>
using namespace std;

queue<int> que;
int main(void) {
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; ++i)
        que.push(i);
    
    vector<int> ans(n, 0);

    int aidx=0;
    while(!que.empty()) {
        int idx=1;
        while(idx != k) {
            que.push(que.front());
            que.pop();
            ++idx;
        }
        ans[aidx++] = que.front();
        que.pop();
    }

    printf("<");
    for(int i=0; i<n; ++i) {
        if(i != n-1)
            printf("%d, ", ans[i]);
        else
            printf("%d>", ans[i]);
    }
}