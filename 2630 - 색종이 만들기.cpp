#include <bits/stdc++.h>
using namespace std;

char paper[128][128];
int white,blue;

void divide(int sx, int ex, int sy, int ey) {
    bool isEnd=true;
    char standard = paper[sy][sx];
    for(int i=sy; i<=ey; ++i) {
        for(int j=sx; j<=ex; ++j) {
            if(paper[i][j] != standard) { isEnd=false; break; }
        }
    }
    if(isEnd) { 
        if(standard=='0') ++white;
        else ++blue;
        return;
    }
    
    int xmid = (ex+sx)/2;
    int ymid = (ey+sy)/2;
    divide(sx,xmid,sy,ymid);
    divide(sx,xmid,ymid+1,ey);
    divide(xmid+1,ex,sy,ymid);
    divide(xmid+1,ex,ymid+1,ey);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            scanf(" %c", &paper[i][j]);
    
    divide(0,n-1,0,n-1);

    printf("%d\n%d", white,blue);
}