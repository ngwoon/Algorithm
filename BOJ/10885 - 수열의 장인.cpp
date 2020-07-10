#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000007

int seq[100000];
long long ans;
int ansTwo;

void check(int idx, int& nowTwo, int& nowMinus) {
    if(seq[idx] == 0) { 
        nowTwo=0; nowMinus=0; 
        return; 
    }
    else if(seq[idx] < 0) {
        ++nowMinus;
        if(seq[idx] == -2) ++nowTwo;
    }
    else if(seq[idx] == 2) ++nowTwo;

    if(nowMinus % 2 == 0) {
        ansTwo = ansTwo < nowTwo ? nowTwo : ansTwo;
        ans = 1;
    }
}

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
        for(int i=0; i<n; ++i)
            check(i, nowTwo, nowMinus);
        
        nowTwo=0; nowMinus=0;
        for(int i=n-1; i>=0; --i)
            check(i, nowTwo, nowMinus);

        while(ansTwo--)
            ans = (ans << 1) % MAX;

        printf("%lld\n", ans);
    }    
}