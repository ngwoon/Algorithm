#include <bits/stdc++.h>
using namespace std;

int s,t,d;

int main(void) {
    scanf("%d %d %d", &s, &t, &d);
    printf("%d", t*(d/(s<<1)));
}