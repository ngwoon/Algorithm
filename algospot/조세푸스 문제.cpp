#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int c, n, k;
    scanf("%d", &c);

    while(c--) {
        scanf("%d %d", &n, &k);

        vector<bool> soldiers(n,true);
        int idx=0, cnt=n;
        while(1) {
            soldiers[idx] = false; --cnt;
            if(cnt == 2)
                break;

            int temp=0;
            while(temp != k) {
                idx = (idx + 1) % n;
                if(soldiers[idx]) ++temp;
            }
        }
        for(int i=0; i<n; ++i) {
            if(soldiers[i])
                printf("%d ", i+1);
        }
    }
}