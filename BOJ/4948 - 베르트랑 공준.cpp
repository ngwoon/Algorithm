#include <bits/stdc++.h>
using namespace std;

#define LIT 260000

int n;
bool isPrime[LIT];

void getPrime() {
    isPrime[1] = false;
    int sqrtN = sqrt(LIT) + 1;
    for(int i=2; i<=sqrtN; ++i) {
        int j=2;
        while(1) {
            int notPrime = i*(j++);
            if(notPrime > LIT) break;
            isPrime[notPrime] = false;
        }
    }
}

int main(void) {
    
    memset(isPrime, true, sizeof(isPrime));
    getPrime();

    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        int cnt=0;
        for(int i=n+1; i<=(n<<1); ++i) {
            if(isPrime[i]) ++cnt; 
        }
        printf("%d\n", cnt);
    }
}