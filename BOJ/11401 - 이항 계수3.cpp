#include <bits/stdc++.h>
#define LIT 1000000007

/*
    11401번 - 이항 계수3

    수학적인 지식을 필요로 하는 문제.
    페르마의 소정리 or 확장 유클리드 호제법 & 베주방정식 으로 풀 수 있다.

    아래 코드는 페르마의 소정리를 활용한 코드이다.
    페르마의 소정리 : p가 소수이고, a가 p의 배수가 아니라면 a^(p-1) % p = 1이다.

    nCk는 n!/k!(n-k)! 이다. 이는 n! * (k!(n-k)!)^-1 로 바꿀 수 있다.
    문제에서 1000000007(이하 LIT)로 나눈 나머지를 출력하라 했는데, 이는 소수이고 k!나 (n-k)!는 LIT의 배수가 될 수 없으므로 페르마의 소정리를 적용할 수 있다.
    즉, k!^(p-1)과 (n-k)!^(p-1)은 1이므로, nCk에 곱해도 값은 변하지 않는다.
    즉 nCk = n! * (k!(n-k)!)^-1 * k!^(p-1) * (n-k)!^(p-1)이고, 이를 정리하면 n! * k!^(p-2) * (n-k)!^(p-2)가 된다.

    1~n까지의 팩토리얼을 구하고, 큰 지수에 대한 거듭제곱은 이전에 배웠던 고속 거듭제곱 알고리즘을 사용하면 시간 내에 구할 수 있다.

    개인적으로 너무 깊은 수학적 지식이 필요하여 난항을 겪었던 문제.
*/
using namespace std;

long long fac[4000001];

// a의 b승을 구하는 함수
long long multi(int a, int b) {
    if(b == 1) return a;

    long long temp = multi(a, b/2);
    long long res = (temp * temp) % LIT;

    if(b % 2 == 0) return res;
    else return ((res * a) % LIT);
}

int main(void) {
    int n,k;
    scanf("%d %d", &n, &k);

    fac[0] = 1;
    for(int i=1; i<=n; ++i)
        fac[i] = fac[i-1]*i % LIT;

    long long a = fac[n];
    long long b = fac[k];
    long long c = fac[n-k];

    b = multi(b, LIT-2);
    c = multi(c, LIT-2);

    long long res = ((a*b % LIT) * c) % LIT;

    printf("%lld", res);
}