#include <bits/stdc++.h>
using namespace std;

vector<int> src;
int mixed=2000000000;
int as, ae;

int main(void) {
    int n;
    scanf("%d", &n);

    src.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &src[i]);

    int s=0, e=n-1;
    while(s < e) {
        int curMixed = src[s] + src[e];
        if(abs(curMixed) < mixed) {
            as = s; ae = e;
            mixed = abs(curMixed);
        }
        if(curMixed < 0) ++s;
        else if(curMixed > 0) --e;
        else break;
    }
    printf("%d %d", src[as], src[ae]);
}