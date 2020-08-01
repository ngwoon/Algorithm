#include <bits/stdc++.h>
using namespace std;

long long tiles[81];

int main(void) {
    int n;
    scanf("%d", &n);

    tiles[0] = 1;
    tiles[1] = 1;
    for(int i=2; i<n; ++i)
        tiles[i] = tiles[i-1] + tiles[i-2];

    long long round = (tiles[n-1] + tiles[n-1] + tiles[n-2]) * 2;
    printf("%lld", round);
}