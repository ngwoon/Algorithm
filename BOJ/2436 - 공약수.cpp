#include <bits/stdc++.h>
using namespace std;

int a,b;

int findGcd(int small, int big) {
    while(small != 0) {
        int rest = big % small;
        big = small;
        small = rest;
    }
    return big;
}

int main(void) {
    scanf("%d %d", &a, &b);

    long long multi = (long long)a*b;
    int r = sqrt(multi);
    for(int i=r; i>=1; --i) {
        if(multi % i == 0) {
            int small = i;
            int big = multi / i;
            if(findGcd(small, big) == a) {
                printf("%d %d", small, big);
                exit(0);
            }
        }
    }
}
