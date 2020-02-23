#include <stdio.h>
#include <utility>
using namespace std;

double dp[1001][2001];
int T, N, M;

double solve(int days, int height) {
    if(days == M) return height >= N ? 1 : 0;

    double& ret = dp[days][height];
    
    if(ret >= 0) return ret;

    ret = solve(days + 1, height + 2)*0.75 + solve(days + 1, height + 1)*0.25;
    return ret;
}

int main(void) {
    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        scanf(" %d %d", &N, &M);

        for(int i=0; i<1001; i++) {
            for(int j=0; j<2001; j++) {
                dp[i][j] = -1;
            }
        }
        
        printf("%.10f\n", solve(0, 0));
    }
}