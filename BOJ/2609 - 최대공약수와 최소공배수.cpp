#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b;
    scanf("%d %d", &a, &b);

    if(a > b) {
        a ^= b; b^= a; a ^= b;
    }

    int gcf, lcm;
    for(int i=1; i<=a; ++i) {
        if(a % i == 0 && b % i == 0)
            gcf = i;
    }

    lcm = a * b / gcf;

    printf("%d\n%d", gcf, lcm);
}