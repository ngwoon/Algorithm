#include <bits/stdc++.h>

/*
    9202 - 골드바흐의 추측

    에라스토테네스의 체 활용 문제.
*?

bool prime[10001];

void getPrime() {

    memset(prime, true, 10000);
    prime[1] = false;
    for(int i=2; i<=100; ++i) {
        int j=2;
        int num = i*j;
        while(num <= 10000) {
            prime[num] = false;
            num = i*(++j);
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    
    getPrime();
    while(t--) {
        int n;
        scanf("%d", &n);

        int left = n/2, right = left;
        while(!prime[left] || !prime[right]) {
            --left; ++right;
        }
        printf("%d %d\n", left, right);
    }
}