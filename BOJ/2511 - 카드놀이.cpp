#include <bits/stdc++.h>
using namespace std;

int a[10];
int b[10];

int main(void) {
    for(int i=0; i<=9; ++i)
        scanf("%d", &a[i]);
    for(int i=0; i<=9; ++i)
        scanf("%d", &b[i]);
    
    int as=0, bs=0;
    char winner='D';
    for(int i=0; i<=9; ++i) {
        if(a[i] > b[i]) { as += 3; winner = 'A'; }
        else if(a[i] < b[i]) { bs += 3; winner = 'B'; }
        else { ++as; ++bs; }
    }

    printf("%d %d\n", as, bs);
    if(as == bs) printf("%c", winner);
    else printf("%c", as > bs ? 'A' : 'B');
}