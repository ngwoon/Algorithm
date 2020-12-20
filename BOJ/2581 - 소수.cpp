#include <bits/stdc++.h>
using namespace std;

int m, n;
bool isPrime[10001];

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
        if(isPrime[i]) primes.push_back(i);
    }

    if(primes.empty()) { printf("-1"); exit(0); }

    int sum=0;
    int minPrime=10001;
    for(int i=0; i<primes.size(); ++i) {
        sum += primes[i];
        if(minPrime > primes[i]) minPrime = primes[i];
    }
    printf("%d\n%d", sum, minPrime);
}