#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000007

/*
    18249번 - 욱제가 풀어야 하는 문제

    dp 기본문제

    문제 잘못 읽어서 몇시간을 버렸냐..
*/

long long cache[191230] = {1,1};
int T;

int main(void) {
    scanf("%d", &T);

    for(int i=2; i<=191229; ++i) {
        cache[i] = cache[i-1] + cache[i-2];
        if(cache[i] >= MAX) cache[i] %= MAX;
    }

    for(int i=0; i<T; ++i) {
        int N;
        scanf(" %d", &N);
        printf("%d\n", cache[N]);
    }
}