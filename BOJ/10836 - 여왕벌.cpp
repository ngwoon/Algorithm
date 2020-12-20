#include <bits/stdc++.h>
using namespace std;

int total[700][700];
int grow[1400];

int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            total[i][j] = 1;

    for(int i=0; i<m; ++i) {
        int idx=0;
        for(int j=0; j<3; ++j) {
            int num;
            scanf("%d", &num);
            while(num--)
                grow[idx++] += j;
        }
    }

    int idx=0;
    for(int j=n-1; j>=0; --j)
        total[j][0] += grow[idx++];
    for(int j=1; j<n; ++j)
        total[0][j] += grow[idx++];

    for(int j=1; j<n; ++j) {
        for(int k=1; k<n; ++k)
            total[j][k] = max(total[j-1][k-1], max(total[j-1][k], total[j][k-1]));
    }

    for(int j=0; j<n; ++j) {
        for(int k=0; k<n; ++k)
            printf("%d ", total[j][k]);
        printf("\n");
    }
}