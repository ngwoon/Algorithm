#include <bits/stdc++.h>
using namespace std;

vector<long long> solution;
long long ans = LLONG_MAX;

int main(void) {
    int n;
    scanf("%d", &n);

    solution.resize(n);
    for(int i=0; i<n; ++i) scanf(" %lld", &solution[i]);

    int i=0, j=n-1;
    while(i<j) {
        long long gap = solution[i] + solution[j];
        if(llabs(gap) < llabs(ans)) ans = gap;

        if(gap == 0) break;
        else if(gap < 0) ++i;
        else --j;
    }
    printf("%lld", ans);
}