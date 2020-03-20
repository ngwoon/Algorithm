#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edges;
vector<int> parent;
int n;

int Find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x != y) {
        if(x > y) { x^=y; y^=x; x^=y; }
        parent[y] = x;
        return true;
    }
    return false;
}

int main(void) {
    scanf("%d", &n);

    parent.resize(n+1);
    for(int i=1; i<=n; ++i) parent[i] = i;

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            int w;
            scanf(" %d", &w);
            edges.push_back({w,i,j});
        }
    }

    sort(edges.begin(), edges.end());

    long long sum=0;
    for(int i=0; i<edges.size(); ++i) {
        if(Union(get<1>(edges[i]), get<2>(edges[i]))) sum += get<0>(edges[i]);
    }

    printf("%lld", sum);
}