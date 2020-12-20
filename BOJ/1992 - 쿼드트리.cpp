#include <bits/stdc++.h>
using namespace std;

char video[64][64];
int n;

void divide(int sx, int ex, int sy, int ey) {
    bool isEnd=true;
    char standard = video[sy][sx];
    for(int i=sy; i<=ey; ++i) {
        for(int j=sx; j<=ex; ++j) {
            if(video[i][j] != standard) { isEnd=false; break; }
        }
    }
    if(isEnd) { printf("%c", standard); return; }

    int xmid = (ex+sx)/2;
    int ymid = (ey+sy)/2;

    printf("(");
    divide(sx,xmid,sy,ymid);
    divide(xmid+1,ex,sy,ymid);
    divide(sx,xmid,ymid+1,ey);
    divide(xmid+1,ex,ymid+1,ey);
    printf(")");
}

int main(void) {
    scanf("%d", &n);

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            scanf(" %c", &video[i][j]);

    divide(0,n-1,0,n-1);
}