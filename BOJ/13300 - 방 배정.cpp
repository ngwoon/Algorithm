#include <bits/stdc++.h>
using namespace std;

int grade[7][2];

int main(void) {
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; ++i) {
        int s, y;
        scanf("%d %d", &s, &y);
        ++grade[y][s];
    }

    int room=0;
    for(int i=1; i<=6; ++i) {
        for(int j=0; j<=1; ++j)
            room += ceil((double)grade[i][j]/k);
    }

    printf("%d", room);
}