#include <bits/stdc++.h>
using namespace std;

int cache[31][31];

int getComb(int n, int r) {
    for(int i=0; i<=n; ++i) cache[i][0] = 1;
    for(int i=0; i<=r; ++i) cache[i][i] = 1;

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=r; ++j)
            cache[i][j] = cache[i-1][j-1] + cache[i-1][j];
    
    return cache[n][r];
}

int main(void) {
    int n,r;
    scanf("%d %d", &n, &r);
    
    printf("%d", getComb(n-1,r-1));
}