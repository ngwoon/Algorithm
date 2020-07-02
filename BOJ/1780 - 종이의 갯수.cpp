#include <bits/stdc++.h>
using namespace std;

int field[2187][2187];
int minusOne,zero,one;

void divide(int sx, int ex, int sy, int ey) {
    bool isEnd=true;
    int standard = field[sy][sx];
    for(int i=sy; i<=ey; ++i) {
        for(int j=sx; j<=ex; ++j) {
            if(field[i][j] != standard) { isEnd=false; goto EXIT; }
        }
    }

EXIT:
    if(isEnd) {
        if(standard == -1) ++minusOne;
        else if(standard == 0) ++zero;
        else ++one;
        return;
    }

    int gap = (ex-sx)/3;
    for(int i=sy; i<=ey; i+=(gap+1)) {
        for(int j=sx; j<=ex; j+=(gap+1)) {
            divide(j,j+gap,i,i+gap);
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) 
        for(int j=0; j<n; ++j)
            scanf(" %d", &field[i][j]);

    divide(0,n-1,0,n-1);

    printf("%d\n%d\n%d",minusOne,zero,one);
}