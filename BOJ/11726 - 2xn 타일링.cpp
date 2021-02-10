#include <bits/stdc++.h>
using namespace std;

int n;
int cache[1001];

int main(void) {
    scanf("%d", &n);

    cache[1] = 1;
    cache[2] = 2;

    for(int i=3; i<=n; ++i)
        cache[i] = (cache[i-2] + cache[i-1]) % 10007;

    printf("%d", cache[n]);
}