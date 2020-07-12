#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n,k;
vector<int> bulb;
int dp[200][200];

int solve(int start, int end) {
    if(start == end)
        return 0;

    int& ret = dp[start][end];
    if(ret == -1) {
        ret = INF;
        for(int i=start; i<end; ++i) {
            int left = solve(start, i);
            int right = solve(i + 1, end);
            int diff;
            if(bulb[start] == bulb[i+1]) diff = 0;
            else diff = 1;

            ret = min(ret, left + right + diff);
        }
    }
    return ret;
}

int main(void) {
    scanf("%d %d", &n, &k);

    bulb.resize(n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &bulb[i]);
    }

    for(int i=0; i<n; ++i)
        fill(dp[i], dp[i] + n, -1);

    printf("%d", solve(0, n-1));
}