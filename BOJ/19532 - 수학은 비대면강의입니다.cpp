#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c,d,e,f;
    int x, y, nb, nc;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    if(a == 0) {
        y = c / b;
        if(e == 0)
            x = f / d;
        else {
            int right = f - e*y;
            x = right / d;
        }
    } else if(b == 0) {
        x = c / a;
        if(d == 0)
            y = f / e;
        else {
            int right = f - d*x;
            y = right / e;
        }
    } else if(d == 0) {
        y = f / e;
        x = (c - b*y) / a;
    } else if(e == 0) {
        x = f / d;
        y = (c - a*x) / b;
    } else {
        int ta = a;
        a *= d; b *= d; c *= d;
        d *= ta; e *= ta; f *= ta;

        if(a == -d) {
            nb = e + b;
            nc = f + c;
        } else {
            nb = b - e;
            nc = c - f;
        }
        y = nc / nb;
        int right = c - b*y;
        x = right/a;
    }
    printf("%d %d", x, y);
}