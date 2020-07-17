#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 100

int n = 99;
unsigned char sieve[(MAX_N+1)/8];

bool isPrime(int num) {
    return sieve[num>>3] & (1<<(num&7));
}

void setComposite(int num) {
    sieve[num>>3] &= ~(1<<(num&7)); // num >> 3은 num/8, num&7은 num % 8을 의미한다.
}

int main(void) {
    memset(sieve, 255, sizeof(sieve)); // sieve 의 모든 비트를 1로 설정
    setComposite(0);
    setComposite(1);

    int sqrtn = (int)sqrt(n);
    for(int i=2; i<=sqrtn; ++i) {
        if(isPrime(i)) {
            printf("현재 : %d\n", i);
            for(int j=i*i; j<=n; j+=i)
                setComposite(j);
        }
    }

    for(int i=1; i<=n; ++i) {
        printf("%d은 %s\n", i, isPrime(i) ? "소수입니다." : "소수가 아닙니다.");
    }
}