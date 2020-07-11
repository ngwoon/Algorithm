#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int degree[100001];

int main(void) {
    int n,k;
    scanf("%d %d", &n, &k);

    degree[0] = 0;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &degree[i]);
        degree[i] += degree[i-1];
    }
    
    int ans=-100000000;
    for(int i=0; i<=n-k; ++i) {
        int sum = degree[i+k] - degree[i];
        ans = ans < sum ? sum : ans;
    }
    printf("%d", ans);
}