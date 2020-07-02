#include <bits/stdc++.h>
using namespace std;

/*
    2156 - 포도주 시식.
    
    dp문제.
    포도주가 k개 있을 때, 포도주를 마시는 시나리오는 아래와 같다.
    1. k-3까지 포도주를 먹고, k-2를 건너뛴 뒤 k-1, k번째 포도주를 마시는 경우
    2. k-2까지 포도주를 먹고, k-1를 건너뛴 뒤 k번째 포도주를 마시는 경우
    3. k-1까지 포도주를 먹고, k번째 포도주는 마시지 않는 경우

    메모이제이션을 이용하여 bottom-up 방식으로 위 3가지 시나리오 중 큰 값을 누적하도록 문제를 풀었다. 
*/

int cache[10001];
int juice[10001];
int n;

int main(void) {
    scanf("%d", &n);

    for(int i=1; i<=n; ++i)
        scanf(" %d", &juice[i]);
    
    cache[1] = juice[1];
    cache[2] = juice[1] + juice[2];

    for(int i=3; i<=n; ++i)
        cache[i] = max(max(cache[i-3] + juice[i-1] + juice[i], cache[i-2] + juice[i]), cache[i-1]);
    
    printf("%d", cache[n]);
}