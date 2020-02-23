#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 12
#define MAX_CLASS_PER_SMTR 10
#define IMP 987654321

using namespace std;

int prerequisite[MAXN];
int classes[10]; // i번째 학기에 열리는 과목의 집합
int dp[10][1<<MAXN];

int T;
int N, K, M, L;

int bitCount(int take) {
    if(take == 0) return 0;
    return take % 2 + bitCount(take / 2);
}

int graduate(int semester, int taken) {
    if(bitCount(taken) >= K) return 0;
    if(semester == M) return IMP;

    int& ret = dp[semester][taken];

    if(ret != -1) return ret;

    ret = IMP;
    
    int canTake = (classes[semester] & ~taken); // 현재 학기에 열린 과목들 중 이미 수강한 과목을 제외한다. (들을 수 있는 과목 골라냄)
    
    // 선이수과목을 다 듣지 못한 과목들을 걸러낸다.
    for(int i=0; i<N; i++) {
        if((canTake & (1<<i)) && (taken & prerequisite[i]) != prerequisite[i])
            canTake &= ~(1<<i);
    }

    // 수강 가능한 과목들의 모든 부분집합을 순회한다.
    for(int take=canTake; take>0; take=((take-1)&canTake)) {
        if(bitCount(take) > L) continue; // 한 학기에 들을 수 있는 과목 수를 초과하면 continue
        
        ret = min(ret, graduate(semester + 1, taken | take) + 1);
    }
    
    // 이번학기에 아무것도 듣지 않은 경우
    ret = min(ret, graduate(semester + 1, taken));
    return ret;
}


int main(void) {
    scanf("%d", &T);

    for(int i=0; i<T; i++) {

        memset(dp, -1, sizeof(dp));
        memset(prerequisite, 0, sizeof(prerequisite));
        memset(classes, 0, sizeof(classes));

        scanf(" %d %d %d %d", &N, &K, &M, &L);

        for(int j=0; j<N; j++) {
            int prereq;
            scanf(" %d", &prereq);
            
            for(int k=0; k<prereq; k++) {
                int temp;
                scanf(" %d", &temp);
                prerequisite[j] |= (1<<temp);
            }
        }

        for(int j=0; j<M; j++) {
            int classes_each_smtr;
            scanf(" %d", &classes_each_smtr);
            
            for(int k=0; k<classes_each_smtr; k++) {
                int temp;
                scanf(" %d", &temp);
                classes[j] |= (1<<temp);
            }
        }

        int res = graduate(0,0);
        if(res == IMP) printf("IMPOSSIBLE\n");
        else printf("%d\n", res);
    }
}