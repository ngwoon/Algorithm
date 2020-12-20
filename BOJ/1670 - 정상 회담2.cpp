#include <bits/stdc++.h>
using namespace std;

/*
    1670번 - 정상회담2

    서로 교차하지 않도록 악수하는 경우의 수를 구하는 문제

    N각형 모양에서 두 명이 악수를 할 때, 위 아래로 인원이 나뉘게 된다. 따라서 dp[N] += dp[k] + dp[N-k] (k=0 -> N, k+=2) 로 나타낼 수 있다.
    즉 dp[k]는 k명이 교차하지 않게 악수하는 경우의 수를 의미한다.
    
    dp문제는 아직 익숙하지 않은 듯 하다.
*/

#define DIV 987654321

long long dp[10001]={0};
int N;

int main(void) {
    scanf("%d", &N);

    dp[0]=1;
    dp[2]=1;
    for(int i=4; i<=N; i+=2) {
        for(int j=0; j<i; j+=2) {
            dp[i] += dp[j] * dp[i-j-2];
            dp[i] %= DIV;
        }
    }
    printf("%lld", dp[N]);
}