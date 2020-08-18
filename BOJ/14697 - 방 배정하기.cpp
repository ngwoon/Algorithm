#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c,n;
    scanf("%d %d %d %d", &a,&b,&c,&n);

    for(int i=0; i<=n/a; ++i) {
        int t1 = i*a;
        for(int j=0; j<=n/b; ++j) {
            int t2 = t1 + j*b;
            for(int k=0; k<=n/c; ++k) {
                int t3 = t2 + k*c;
                if(t3 == n) {
                    printf("1");
                    exit(0);
                }
            }
        }
    }
    printf("0");
}