#include <bits/stdc++.h>
using namespace std;

vector<int> logs;
vector<int> ans;
int N;

int main(void) {
    scanf("%d", &N);
    logs.resize(N);
    for(int i=0; i<N; ++i) scanf(" %d", &logs[i]);

    ans.resize(N+1,-2);
    ans[logs[0]] = -1;
    for(int i=1; i<N; ++i) {
        if(ans[logs[i]] == -2) ans[logs[i]] = logs[i-1];
    }
        
    int cnt=1;
    while(ans[cnt] != -2) ++cnt;

    printf("%d\n", cnt);
    for(int i=0; i<cnt; ++i) printf("%d ", ans[i]);
}