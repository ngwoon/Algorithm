#include <bits/stdc++.h>
using namespace std;

int after[30], before[30];

int main(void) {
    int n;

    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &after[i]);

    before[0] = after[0];
    int cnt=1, idx = before[0] % n;
    while(cnt < n) {
        while(before[idx] != 0)
            idx = (idx + 1) % n;
        
        before[idx] = after[cnt];
        ++cnt;
        idx = (idx + before[idx]) % n;
    }
    printf("%d\n", n);
    for(int i=0; i<n; ++i)
        printf("%d ", before[i]);
}