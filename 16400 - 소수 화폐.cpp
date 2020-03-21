#include <bits/stdc++.h>
using namespace std;

/*
    16400번 - 소수 화폐

    동전 dp문제는 2가지 유형이 있다. 
    1. 목표 금액을 맞추기 위해 필요한 최소 동전 갯수 찾기
    2. 목표 금액을 맞출 수 있는 동전 조합의 수

    이 문제는 2번에 해당한 문제이고, 사용 가능한 동전이 "소수" 값을 가지면 되므로
    coins 벡터에 소수를 찾아 넣은 뒤 동전 dp 코드를 쓰면 된다.
*/

#define MAX 123456789

long long dp[40001];
vector<int> coins;
int n;

void getPrime() {
    bool isPrime[n+1];
    memset(isPrime, true, n+1);

    isPrime[0]=false; isPrime[1]=false;
    int end = sqrt(n) + 1;
    for(int i=2; i<=end; ++i) {
        int temp=2;
        while(1) {
            int index=i*temp;
            if(index > n) break;
            isPrime[index]=false;
            ++temp;
        }
    }

    for(int i=0; i<=n; ++i) {
        if(isPrime[i]) coins.push_back(i);
    }
}

int main(void) {
    scanf("%d", &n);
    getPrime();

    dp[0] = 1;
    for(int i=0; i<coins.size(); ++i) {
        for(int j=coins[i]; j<=n; ++j) {
            dp[j] = (dp[j] + dp[j-coins[i]]) % MAX;
        }
    }
    printf("%d", dp[n]);
}