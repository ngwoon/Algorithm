#include <bits/stdc++.h>
using namespace std;

long long cache[2][91];
int n;

int main(void) {
    scanf("%d", &n);

    cache[0][1] = 0;
    cache[1][1] = 1;
    cache[0][2] = 1;
    cache[1][2] = 0;

    for(int i=3; i<=n; ++i) {
        cache[1][i] = cache[0][i-1];
        cache[0][i] = cache[1][i-1] + cache[0][i-1];
    }

    printf("%lld", cache[0][n] + cache[1][n]);
}