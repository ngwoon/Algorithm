#include <bits/stdc++.h>
using namespace std;

/*
    14922번 - 부분 평균

    모든 구간의 부분 평균을 구하려면 시간초과가 난다.
    문제 아래에 힌트가 있는데, 0<=P,Q<=N 이고 P+1<Q 일 때, P,Q 사이에 존재하는 K에 대하여
    P~K평균 <= P~Q평균 <= K+1~Q평균을 만족하는 K가 존재한다.
    즉, 구간이 4 이상인 부분에 대해서 항상 그보다 작은 부분평균이 존재함을 알 수 있다.
    단, 구간이 3일 땐 K+1~Q 혹은 P~K 부분평균을 구할 때, K+1 == Q 혹은 P == K 인 경우가 있으므로 위 힌트를 적용시킬 수 없다.
    따라서 구간이 2,3인 부분평균만 확인해 주면 되므로 시간복잡도가 확 줄어든다.
*/

vector<int> subsum;
int n;
double minAvg = 987654321;
int ans;

int main(void) {
    scanf("%d", &n);
    subsum.resize(n+1,0);
    for(int i=1; i<=n; ++i) {
        scanf(" %d", &subsum[i]);
        subsum[i] += subsum[i-1];
    }

    for(int i=1; i<n; ++i) {
        int start=i;
        for(int j=start+1; j<=n && j<=start+2; ++j) {
            int end=j;
            double avg = (subsum[end]-subsum[start-1]) / (double)(end-start+1);
            if(avg < minAvg) { minAvg = avg; ans = start-1; }
        }
    }
    printf("%d", ans);
}