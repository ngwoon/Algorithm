#include <bits/stdc++.h>
using namespace std;

bool line[10001];
int n,ans;

int main(void) {
    scanf("%d", &n);
    
    int s,e;
    for(int i=0; i<n; ++i) {
        scanf(" %d %d", &s, &e);
        for(int j=s; j<e; ++j) line[j]=true;
    }
    for(int i=1; i<=10000; ++i) {
        while(line[i]) { ++ans; ++i; }
    }
    printf("%d", ans);
}