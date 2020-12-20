#include <bits/stdc++.h>
using namespace std;

/*
    11053 - 가장 긴 증가하는 부분 수열

    대표적인 LIS 문제.

    LIS 문제를 푸는 방법에는 완전탐색, 동적 계획법이 있다.
    아래 코드는 동적 계획법을 사용한 코드로, dp 배열의 인덱스(k)가 의미하는 바는 아래와 같다.
    "k 인덱스부터 마지막 인덱스까지의 부분수열 중 가장 길이가 긴 수열의 길이"
*/

int dp[1001];
int seq[1001];
int n;

int solve(int start) {
    int& ret = dp[start];
    if(ret == 0) {
        for(int i=start + 1; i<=n; ++i) {
            if(seq[i] > seq[start])
                ret = max(ret, solve(i) + 1);
        }
        if(ret == 0)
            ret = 1;
    }
    return ret;
}

int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &seq[i]);

    for(int i=1; i<=n; ++i)
        solve(i);

    int maxVal = 0;
    for(int i=1; i<=n; ++i) {
        if(maxVal < dp[i])
            maxVal = dp[i];
    }
    printf("%d", maxVal);
}


// #include <bits/stdc++.h>
// using namespace std;

// int seq[1001];
// int n, ans;

// void solve(int index, int length) {
//     if(index == n-1) {
//         ans = max(ans, length);
//         return;
//     }

//     for(int i=index+1; i<n; ++i) {
//         if(seq[index] < seq[i])
//             solve(i, length + 1);
//     }
// }

// int main(void) {
//     scanf("%d", &n);
//     for(int i=0; i<n; ++i)
//         scanf("%d", &seq[i]);
    
//     for(int i=0; i<n; ++i)
//         solve(i, 1);

//     printf("%d", ans);
// }