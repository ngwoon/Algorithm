// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<char>> field;
// int m,n;
// int ans=0;

// int main(void) {
//     scanf("%d %d", &m, &n);

//     field.resize(m);
//     for(int i=0; i<m; ++i) field[i].resize(n);
//     for(int i=0; i<m; ++i)
//         for(int j=0; j<n; ++j)
//             scanf(" %c", &field[i][j]);

//     for(int i=0; i<m; ++i) {
//         for(int j=0; j<n; ++j) {
//             if(field[i][j] != '0') continue;
//             int col=j, row=i;
//             int len=0;
//             while(col < n && row < m) {
//                 // 행 검사
//                 int k;
//                 for(k=j; k<=col; ++k) {
//                     if(field[row][k] != '0') break;
//                 }
//                 if(k != col+1) break;

//                 // 열 검사
//                 for(k=i; k<=row; ++k) {
//                     if(field[k][col] != '0') break;
//                 }
//                 if(k != row+1) break;

//                 ++len; ++col; ++row;
//             }
//             if(len > ans) ans = len;
//         }
//     }
//     printf("%d", ans);
// }

#include <bits/stdc++.h>
using namespace std;

/*
    14925번 - 목장 건설하기

    나는 브루트 포스를 최적화해서 풀었지만, 시간복잡도가 굉장히 안좋길래 다른 사람의 풀이를 보았더니 dp로 풀었다.
    다른 이의 풀이를 참고하여 다시 제출했더니 10배 이상의 좋은 시간을 보였다.
    동적계획법을 언제 써야 하는가에 대한 공부가 훨씬 더 많이 이루어져야 할 듯 하다.
*/

int dp[1001][1001];
int m,n,maxVal;
char c;

int main(void) {
    scanf("%d %d", &m, &n);
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            scanf(" %c", &c);
            if(c == '0') {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxVal = maxVal < dp[i][j] ? dp[i][j] : maxVal;
            }
        }
    }
    printf("%d", maxVal);
}