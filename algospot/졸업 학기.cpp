#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int pre[12];
int subInfo[10];
int cache[10][1<<12];
int c, n, k, m, l;

int solve(int curSem, int taken) {
    if(__builtin_popcount(taken) >= k)
        return 0;
    if(curSem == m)
        return INF;

    int& ret = cache[curSem][taken];
    if(ret == -1) {
        ret = INF;
        
        int canTake = (subInfo[curSem] & ~taken);
        // canTake 중 선수과목을 이수하지 않은 과목 제거
        for(int i=0; i<n; ++i) {
            if((canTake & (1<<i)) && ((taken & pre[i]) != pre[i]))
                canTake &= ~(1<<i);
        }

        // 이번 학기에 들을 수 있는 과목들의 부분집합을 전부 순회
        for(int take=canTake; take > 0; take = (take-1) & canTake) {
            if(__builtin_popcount(take) > l) continue;
            ret = min(ret, solve(curSem + 1, taken | take) + 1);
        }
    }

    // 휴학하는 경우 고려
    ret = min(ret, solve(curSem + 1, taken));
    return ret;
}

int main(void) {
    scanf("%d", &c);
    while(c--) {
        memset(pre, 0, sizeof(pre));
        memset(subInfo, 0, sizeof(subInfo));
        memset(cache, -1, sizeof(cache));

        scanf("%d %d %d %d", &n, &k, &m, &l);

        for(int i=0; i<n; ++i) {
            int r;
            scanf("%d", &r);
            for(int j=0; j<r; ++j) {
                int presub;
                scanf("%d", &presub);
                pre[i] |= (1<<presub);
            }
        }

        for(int i=0; i<m; ++i) {
            int ci;
            scanf("%d", &ci);
            for(int j=0; j<ci; ++j) {
                int subject;
                scanf("%d", &subject);
                subInfo[i] |= (1<<subject);
            }
        }

        int res = solve(0, 0);
        if(res == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", res);
    }
}   