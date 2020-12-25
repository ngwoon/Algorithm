#include <bits/stdc++.h>
using namespace std;

int n,m;
int parent[1000001];

int Find(int x) {
    if(x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    if(a > b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    parent[b] = a;
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &n, &m);

    for(int i=0; i<=n; ++i)
        parent[i] = i;

    for(int i=0; i<m; ++i) {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);

        int _a = Find(a);
        int _b = Find(b);

        if(op == 0)
            Union(_a, _b);
        else {
            if(_a == _b)
                printf("YES");
            else
                printf("NO");
            printf("\n");
        }
    }
}