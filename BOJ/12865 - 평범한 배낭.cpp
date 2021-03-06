#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> stuff;
vector<vector<int>> cache;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    stuff.resize(n+1);
    for(int i=1; i<=n; ++i) {
        int w, v;
        scanf("%d %d", &w, &v);
        stuff[i] = {w, v};
    }

    cache.resize(k+1);
    for(int i=0; i<=k; ++i)
        cache[i].resize(n+1, 0);
    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=k; ++j) {
            if(stuff[i].first > j)
                cache[j][i] = cache[j][i-1];
            else
                cache[j][i] = max(cache[j][i-1], cache[j-stuff[i].first][i-1] + stuff[i].second);
        }
    }

    printf("%d", cache[k][n]);
}