#include <bits/stdc++.h>
using namespace std;

int field[15][15];
int ans;

int main(void) {
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j)
            field[i][j] = 1;
    }

    if(k == 0) {
        for(int i=1; i<n; ++i) {
            for(int j=1; j<m; ++j)
                field[i][j] = field[i-1][j] + field[i][j-1];
        }
        ans = field[n-1][m-1];
    } else {
        k -= 1;
        int ln = k / m, lm = k % m;
        int rn = n-1, rm = m-1;

        for(int i=1; i<=ln; ++i) {
            for(int j=1; j<=lm; ++j)
                field[i][j] = field[i-1][j] + field[i][j-1];
        }
        for(int i=ln+1; i<=rn; ++i) {
            for(int j=lm+1; j<=rm; ++j)
                field[i][j] = field[i-1][j] + field[i][j-1];
        }
        ans = field[ln][lm] * field[rn][rm];
    }

    // for(int i=0; i<n; ++i) {
    //     for(int j=0; j<m; ++j)
    //         printf("%d ", field[i][j]);
    //     printf("\n");
    // }

    printf("%d", ans);
}