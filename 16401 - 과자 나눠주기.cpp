#include <bits/stdc++.h>
using namespace std;

vector<int> snack;
int m,n;
int ans;

int main(void) {
    scanf("%d %d", &m, &n);
    snack.resize(n);
    for(int i=0; i<n; ++i) scanf(" %d", &snack[i]);

    sort(snack.begin(), snack.end());

    int low=1, high=1000000000;
    while(low <= high) {
        int mid = (low + high)/2;

        int cnt=0;
        for(int i=0; i<n; ++i) {
            if(snack[i] >= mid) cnt += snack[i] / mid;
        }
        if(cnt >= m) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }

    printf("%d", ans);
}