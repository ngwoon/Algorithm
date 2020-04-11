#include <bits/stdc++.h>
using namespace std;

int n;
bool isPrime[1001];

void getPrime() {
    isPrime[1] = false;
    for(int i=2; i<=100; ++i) {
        int j=2;
        while(1) {
            int notPrime = i*(j++);
            if(notPrime > 1000) break;
            isPrime[notPrime] = false;
        }
    }
}

int main(void) {
    scanf("%d", &n);
    
    memset(isPrime, true, sizeof(isPrime));
    getPrime();

    int input;
    int cnt=0;
    for(int i=0; i<n; ++i) {
        scanf(" %d", &input);
        if(isPrime[input]) ++cnt;
    }
    printf("%d", cnt);
}