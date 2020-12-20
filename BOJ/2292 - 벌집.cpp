#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int limit=1;
    int n;
    scanf("%d", &n);

    for(int i=0;;++i) {
        limit += i*6;
        if(n <= limit) { printf("%d", i+1); exit(0); }
    }
}