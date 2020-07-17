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
    sieve[num>>3] &= ~(1<<(num&7)); // num >> 3�� num/8, num&7�� num % 8�� �ǹ��Ѵ�.
}

int main(void) {
    memset(sieve, 255, sizeof(sieve)); // sieve �� ��� ��Ʈ�� 1�� ����
    setComposite(0);
    setComposite(1);

    int sqrtn = (int)sqrt(n);
    for(int i=2; i<=sqrtn; ++i) {
        if(isPrime(i)) {
            printf("���� : %d\n", i);
            for(int j=i*i; j<=n; j+=i)
                setComposite(j);
        }
    }

    for(int i=1; i<=n; ++i) {
        printf("%d�� %s\n", i, isPrime(i) ? "�Ҽ��Դϴ�." : "�Ҽ��� �ƴմϴ�.");
    }
}