#include <bits/stdc++.h>
using namespace std;

/*
    2565 - 전깃줄

    LIS 응용 문제.

    전깃줄이 교차하지 않으려면, A 전봇대를 오름차순으로 정렬 후, 앞 인덱스서부터 대응하는 B 전봇대의 번호가 항상 증가해야 한다.
    <11053 - 가장 긴 증가하는 부분 수열> 문제에서 사용한 LIS 알고리즘을 적용했다.
    --> 즉, dp 배열은 k인덱스부터 마지막 인덱스까지의 전깃줄 중 전깃줄들이 교차하지 않는 상태를 유지하면서 전깃줄을 최대로 사용하는 경우의 수를 의미한다.
    문제에서 묻는 건 제거해야하는 최소 전깃줄 수이므로, n에서 dp배열의 최대값을 빼면 답이 된다.
*/

int n;
vector<pair<int, int>> seq;
int dp[101];

int solve(int start) {
    int& ret = dp[start];
    if(ret == 0) {
        for(int i=start+1; i<n; ++i) {
            if(seq[i].second > seq[start].second) {
                ret = max(ret, solve(i) + 1);
            }
        }
        if(ret == 0)
            ret = 1;
    }
    return ret;
}

int main(void) {
    scanf("%d", &n);

    seq.resize(n, {0,0});
    for(int i=0; i<n; ++i)
        scanf("%d %d", &seq[i].first, &seq[i].second);
    
    sort(seq.begin(), seq.end());
    dp[n-1] = 1;

    for(int i=0; i<n; ++i)
        solve(i);

    int maxVal = 0;
    for(int i=0; i<n; ++i) {
        if(maxVal < dp[i]) maxVal = dp[i];
    }

    printf("%d", n - maxVal);
}