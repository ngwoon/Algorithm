#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n,m;

    scanf("%d %d", &n, &m);

    vector<int> cards(n+1);
    for(int i=1; i<=n; ++i)
        cards[i] = i;
    
    for(int i=0; i<m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        ++cards[x]; --cards[y];
    }

    vector<bool> check(n+1, false);
    for(int i=1; i<=n; ++i) {
        if(check[cards[i]]) {
            printf("-1");
            exit(0);
        } else
            check[cards[i]] = true;
    }

    for(int i=1; i<=n; ++i)
        printf("%d ", cards[i]);
}