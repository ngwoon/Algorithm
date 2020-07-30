#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int m;
    scanf("%d", &m);

    long long rpm = 1;
    int dir = 0;
    for(int i=0; i<m; ++i) {
        int a,b,s;
        scanf("%d %d %d", &a, &b, &s);
        rpm = (rpm*b)/a;
        if(s == 1) dir ^= 1;
    }

    printf("%d %lld", dir, rpm);
}