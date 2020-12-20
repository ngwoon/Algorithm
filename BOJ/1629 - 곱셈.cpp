#include <bits/stdc++.h>
using namespace std;

/*
    1629번 - 곱셈
    a,b,c가 최대 int형 정수 최댓값과 같을 수 있어, 일반적인 거듭제곱 연산이나 분할정복을 그대로 사용하면 TLE가 날 수 있다.
    거듭제곱이기 때문에, 분할정복을 사용 시 같은 연산을 하는 함수호출이 중복되어 일어날 수 있음을 이용한다.
    함수 호출을 한 번만 하여, 해당 리턴값을 제곱하는 방식으로 구현이 가능하다.
    지수가 짝수/홀수 일 경우 계산이 다르므로, 신경 써 주어야 한다. 
*/

int a,b,c;

long long divmul(int base, int indices) {
    if(indices == 0) return 1;

    long long k = divmul(base, indices/2);
    long long res = (k*k) % c;

    if(indices%2==0) return res;
    else return res * base % c;
}

int main(void) {
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld",divmul(a,b));
}