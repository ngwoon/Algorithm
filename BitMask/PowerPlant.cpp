#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/*
    백준 1102 - 발전소

    보통의 비트마스크 + dp 문제에서 고려하는 경로를 고려하지 않고 풀어야 했던 문제

    dp + 비트마스크 알고리즘 형태를 어서 익혀야 이러한 응용 문제도 쉽게쉽게 연상이 가능할 듯 싶다.
*/

#define IMP 1000

int N,P;
int weight[16][16];
int dp[1<<16];

int repair(int stat) {
    int& ret = dp[stat];

    if(ret != -1) return ret;

    int cnt=0;
    for(int i=0; i<N; i++) {
        if(stat & (1<<i)) ++cnt;
    }
    if(cnt >= P) return 0;

    ret = IMP;
    for(int i=0; i<N; i++) {
        if(stat & (1<<i)) continue;
        
        for(int j=0; j<N; j++) {
            if(stat & (1<<j))
                ret = min(ret, repair(stat | (1<<i)) + weight[j][i]);
        }
    }

    return ret;
}

int main(void) {
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &weight[i][j]);

    int stat=0;
    for(int i=0; i<N; i++) {
        char temp;
        scanf(" %c", &temp);
        stat |= (temp=='Y' ? (1<<i) : 0);
    }
    scanf("%d", &P);

    memset(dp, -1, sizeof(dp));

    int result = repair(stat);

    printf("%d", (result==IMP ? -1 : result));
}