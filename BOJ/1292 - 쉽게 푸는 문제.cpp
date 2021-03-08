#include <bits/stdc++.h>
using namespace std;

int arr[500501];

int main(void) {
    int a,b;
    scanf("%d %d", &a, &b);

    int idx=1;
    int num=1;
    int acc=0;
    while(acc < b) {
        acc += num;
        for(int i=0; i<num; ++i)
            arr[idx++] = num;
        ++num;
    }

    int ans=0;
    for(int i=a; i<=b; ++i)
        ans += arr[i];

    printf("%d", ans);
}