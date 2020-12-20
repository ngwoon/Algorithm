#include <bits/stdc++.h>
using namespace std;

/*
    1577번 - 도로의 갯수

    고등학교 시절 순열과 조합 수학문제 유형 중 하나인 문제.
    (0,0) 에서 (i,j) 까지 도달할 수 있는 도로의 갯수는 (i-1,j) + (i,j-1) 이다.
    단, 공사중인 도로가 있기 때문에, 해당 도로를 거쳐 오는 경우의 수를 제외해 주어야 한다.

    점화식이 간단하므로 dp로 쉽게 풀리는 문제.
*/

vector<pair<pair<int, int>, pair<int, int>>> cons;
vector<vector<long long>> dp;
int n,m,k;
long long ans;

int main(void) {
    scanf("%d %d", &n, &m);

    dp.resize(m+2);
    for(int i=0; i<=m+1; ++i) dp[i].resize(n+2, 0);

    scanf(" %d", &k);

    cons.resize(k);
    for(int i=0; i<k; ++i) {
        int x1,y1,x2,y2;
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        ++x1; ++y1; ++x2; ++y2;
        if(y1 > y2 || x1 > x2) {
            y1 ^= y2; y2 ^= y1; y1 ^= y2;
            x1 ^= x2; x2 ^= x1; x1 ^= x2;
        }
        cons[i] = {{y1,x1}, {y2,x2}};
    }

    dp[0][1] = 1;
    for(int i=1; i<=m+1; ++i) {
        for(int j=1; j<=n+1; ++j) {
            bool grIsCons=false, gdIsCons=false;
            for(int z=0; z<cons.size(); ++z) {
                if(cons[z] == make_pair(make_pair(i,j-1), make_pair(i,j))) grIsCons=true;
                else if(cons[z] == make_pair(make_pair(i-1,j), make_pair(i,j))) gdIsCons=true;
                
                if(grIsCons && gdIsCons) break;
            }

            if(!grIsCons && !gdIsCons) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else if(grIsCons && !gdIsCons) dp[i][j] = dp[i-1][j];
            else if(!grIsCons && gdIsCons) dp[i][j] = dp[i][j-1];
            else dp[i][j] = 0;
        }
    }
    printf("%lld", dp[m+1][n+1]);
}