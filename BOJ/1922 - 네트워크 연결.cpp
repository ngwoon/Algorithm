#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<tuple<int, int, int>> edge;


int Find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    if(x != y) {
        if(x > y) { x ^= y; y ^= x; x ^= y; }
        parent[y] = x;
        return true;
    }

    return false;
}

int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);

    parent.resize(n+1);
    for(int i=1; i<=n; ++i) parent[i] = i;

    edge.resize(m);
    for(int i=0; i<m; ++i) {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);
        edge[i] = {w,v1,v2};
    }

    sort(edge.begin(), edge.end());

    int sum=0;
    for(int i=0; i<m; ++i) {
        if(Union(get<1>(edge[i]), get<2>(edge[i]))) sum += get<0>(edge[i]);
    }
    printf("%d", sum);
}