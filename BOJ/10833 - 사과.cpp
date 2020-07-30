#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    int ans=0;
    for(int i=0; i<n; ++i) {
        int s, a;
        scanf("%d %d", &s, &a);
        ans += a % s;
    }
    printf("%d", ans);
}