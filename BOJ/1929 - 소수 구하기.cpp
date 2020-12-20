#include <bits/stdc++.h>
using namespace std;

int m, n;
bool isPrime[1000001];

void getPrime() {
    isPrime[1] = false;
    int sqrtN = sqrt(n) + 1;
    for(int i=2; i<=sqrtN; ++i) {
        int j=2;
        while(1) {
            int notPrime = i*(j++);
            if(notPrime > n) break;
            isPrime[notPrime] = false;
        }
    }
}

int main(void) {
    scanf("%d %d", &m, &n);

    memset(isPrime, true, sizeof(isPrime));
    getPrime();

    vector<int> primes;

    for(int i=m; i<=n; ++i) {
        if(isPrime[i]) printf("%d\n", i);
    }
}