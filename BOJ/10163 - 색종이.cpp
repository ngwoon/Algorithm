#include <bits/stdc++.h>
using namespace std;

int field[101][101];
int cnt[101];

int main(void) {
    int n;
    scanf("%d", &n);

    memset(field, -1, sizeof(field));
    for(int i=0; i<n; ++i) {
        int sx, sy, w, h;
        scanf("%d %d %d %d", &sx, &sy, &w, &h);

        for(int j=sy; j<sy + h; ++j) {
            for(int k=sx; k<sx + w; ++k)
                field[j][k] = i;
        }
    }

    for(int i=0; i<101; ++i) {
        for(int j=0; j<101; ++j) {
            if(field[i][j] != -1)
                ++cnt[field[i][j]];
        }
    }

    for(int i=0; i<n; ++i)
        printf("%d\n", cnt[i]);
}