#include <bits/stdc++.h>
using namespace std;

/*
    10844 - 쉬운 계단 수

    dp문제.

    모든 경우의 수를 다 구하는 방법은 시간초과가 날 수 있다.
    메모이제이션을 이용하는데, 본인의 경우 n번째 수가 k일 때의 값을 저장해두어
    top-dodwn 방식으로 경우의 수를 누적하여 답을 구했다.

*/

#define limit 1000000000

long long cache[101][10];
int n;

int solve(int length, int num) {
    if(length == n)
        cache[length][num] = 1;
    
    long long& ret = cache[length][num];
    if(ret == 0) {
        if(num - 1 >= 0)
            ret += solve(length + 1, num - 1);
        if(num + 1 <= 9)
            ret += solve(length + 1, num + 1);
        
        ret %= limit;
    }

    return ret;
}

int main(void) {
    scanf("%d", &n);

    for(int i=1; i<=9; ++i)
        solve(1, i);

    long long ans = 0;
    for(int i=1; i<=9; ++i) {
        ans += cache[1][i];
        ans %= limit;
    }

    printf("%lld", ans);
}