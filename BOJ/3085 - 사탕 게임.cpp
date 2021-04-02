#include <bits/stdc++.h>
using namespace std;

int n,ans;
vector<vector<char>> candies;

int main(void) {
    scanf("%d", &n);

    candies.resize(n);
    for(int i=0; i<n; ++i)
        candies[i].resize(n);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            scanf(" %c", &candies[i][j]);
    }

    for(int i=0; i<n; ++i) {
        int temp=0;
        for(int j=0; j<n-1; ++j) {
            if(candies[i][j] == candies[i][j+1]) {
                if(temp == 0)   
                    temp=2;
                else
                    ++temp;
            } else {
                ans = ans < temp ? temp : ans;
                temp=0;
            }
        }
        ans = ans < temp ? temp : ans;
    }

    for(int j=0; j<n; ++j) {
        int temp=0;
        for(int i=0; i<n-1; ++i) {
            if(candies[i][j] == candies[i+1][j]) {
                if(temp == 0)   
                    temp=2;
                else
                    ++temp;
            } else {
                ans = ans < temp ? temp : ans;
                temp=0;
            }
        }
        ans = ans < temp ? temp : ans;
    }

    // 같은 행 캔디 바꾸기
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n-1; ++j) {

            if(candies[i][j] == candies[i][j+1])
                continue;

            candies[i][j] ^= candies[i][j+1];
            candies[i][j+1] ^= candies[i][j];
            candies[i][j] ^= candies[i][j+1];

            int temp=0;
            for(int k=0; k<n-1; ++k) {
                if(candies[i][k] == candies[i][k+1]) {
                    if(temp == 0)
                        temp = 2;
                    else
                        ++temp;
                }
                else {
                    ans = ans < temp ? temp : ans;
                    temp=0;
                }
            }
            ans = ans < temp ? temp : ans;

            temp=0;
            for(int k=0; k<n-1; ++k) {
                if(candies[k][j] == candies[k+1][j]) {
                    if(temp == 0)
                        temp = 2;
                    else
                        ++temp;
                }
                else {
                    ans = ans < temp ? temp : ans;
                    temp=0;
                }
            }
            ans = ans < temp ? temp : ans;

            temp=0;
            for(int k=0; k<n-1; ++k) {
                if(candies[k][j+1] == candies[k+1][j+1]) {
                    if(temp == 0)
                        temp = 2;
                    else
                        ++temp;
                }
                else {
                    ans = ans < temp ? temp : ans;
                    temp=0;
                }
            }
            ans = ans < temp ? temp : ans;

            candies[i][j] ^= candies[i][j+1];
            candies[i][j+1] ^= candies[i][j];
            candies[i][j] ^= candies[i][j+1];
        }   
    }

    // 같은 열 캔디 바꾸기
    for(int j=0; j<n; ++j) {
        for(int i=0; i<n-1; ++i) {
            if(candies[i][j] == candies[i+1][j])
                continue;

            candies[i][j] ^= candies[i+1][j];
            candies[i+1][j] ^= candies[i][j];
            candies[i][j] ^= candies[i+1][j];

            int temp=0;
            for(int k=0; k<n-1; ++k) {
                if(candies[i][k] == candies[i][k+1]) {
                    if(temp == 0)
                        temp = 2;
                    else
                        ++temp;
                }
                else {
                    ans = ans < temp ? temp : ans;
                    temp=0;
                }
            }
            ans = ans < temp ? temp : ans;

            temp=0;
            for(int k=0; k<n-1; ++k) {
                if(candies[i+1][k] == candies[i+1][k+1]) {
                    if(temp == 0)
                        temp = 2;
                    else
                        ++temp;
                }
                else {
                    ans = ans < temp ? temp : ans;
                    temp=0;
                }
            }
            ans = ans < temp ? temp : ans;

            temp=0;
            for(int k=0; k<n-1; ++k) {
                if(candies[k][j] == candies[k+1][j]) {
                    if(temp == 0)
                        temp = 2;
                    else
                        ++temp;
                }
                else {
                    ans = ans < temp ? temp : ans;
                    temp=0;
                }
            }
            ans = ans < temp ? temp : ans;

            candies[i][j] ^= candies[i+1][j];
            candies[i+1][j] ^= candies[i][j];
            candies[i][j] ^= candies[i+1][j];
        }   
    }

    printf("%d", ans);
}