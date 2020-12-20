#include <bits/stdc++.h>
using namespace std;

int stk[100001];
int idx=-1;

int main(void) {
    int k;
    scanf("%d", &k);

    memset(stk, -1, sizeof(stk));
    for(int i=0; i<k; ++i) {
        int num;
        scanf("%d", &num);
        if(num == 0)
            stk[idx--] = -1;
        else
            stk[++idx] = num;
    }

    int sum=0;
    idx=0;
    while(stk[idx] != -1) {
        sum += stk[idx++];
    }

    printf("%d", sum);
}