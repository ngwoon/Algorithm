#include <bits/stdc++.h>
using namespace std;

vector<int> psum;
vector<int> cost;
int dp[501][501];
int t,z;

int main(void) {
    scanf("%d", &t);

    for(int k=0; k<t; ++k) {
        scanf(" %d", &z);

        cost.resize(z); psum.resize(z+1);
        for(int i=0; i<z; ++i) {
            scanf(" %d", &cost[i]);
            psum[i+1] = cost[i];
        }

        for(int i=1; i<z; ++i) psum[i+1] += psum[i];

        for(int i=1; i<z; ++i) {
            for(int x=1; x+i<=z; ++x) {
                int y = x + i;
                dp[x][y] = INT_MAX;
                
                for(int mid=x; mid<y; ++mid)
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + psum[y] - psum[x-1]);
            }
        }
        printf("%d\n", dp[1][z]);

        for(int i=0; i<=z; ++i)
            memset(dp[i], 0, sizeof(int)*(z+1));
    }
}