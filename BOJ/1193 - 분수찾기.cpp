#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x;
    scanf("%d", &x);

    int top = 1;
    int sum = 1;
    while(sum <= x) {
        ++top;
        sum += top;
    }
    
    int bottom = 1;
    while(sum != x) {
        --sum; ++bottom; --top;
        if(top == 0) { top = bottom - 2; bottom = 1; }
    }

    if((top + bottom) % 2 == 1) printf("%d/%d", top, bottom);
    else printf("%d/%d", bottom, top);
}