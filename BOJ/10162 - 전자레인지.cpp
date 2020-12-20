#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    int five = n/300;
    n -= five * 300;
    int one = n/60;
    n -= one * 60;
    int ten = n/10;
    n -= ten * 10;

    if(n > 0)
        printf("-1");
    else
        printf("%d %d %d", five, one, ten);
}