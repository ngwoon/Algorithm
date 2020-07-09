#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000007

int seq[100000];
long long ans;
int ansTwo;

int main(void) {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        ans = -3; ansTwo = 0;

        for(int i=0; i<n; ++i) {
            scanf("%d", &seq[i]);
            ans = ans < seq[i] ? seq[i] : ans;
        }

        int nowTwo=0, nowMinus=0;
        for(int i=0; i<n; ++i) {
            if(seq[i] == 0) { nowTwo=0; nowMinus=0; continue; }
            else if(seq[i] < 0) {
                ++nowMinus;
                if(seq[i] == -2) ++nowTwo;
            }
            else if(seq[i] == 2) ++nowTwo;

            if(nowMinus % 2 == 0) {
                ansTwo = ansTwo < nowTwo ? nowTwo : ansTwo;
                ans = 1;
            }
        }

        nowTwo=0; nowMinus=0;
        for(int i=n-1; i>=0; --i) {
            if(seq[i] == 0) { nowTwo=0; nowMinus=0; continue; }
            else if(seq[i] < 0) {
                ++nowMinus;
                if(seq[i] == -2) ++nowTwo;
            }
            else if(seq[i] == 2) ++nowTwo;

            if(nowMinus % 2 == 0) {
                ansTwo = ansTwo < nowTwo ? nowTwo : ansTwo;
                ans = 1;
            }
        }

        while(ansTwo--)
            ans = (ans << 1) % MAX;

        printf("%lld\n", ans);
    }    
}