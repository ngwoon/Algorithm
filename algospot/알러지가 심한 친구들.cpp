#include <bits/stdc++.h>
using namespace std;

#define INF 987654321;

vector<string> names;
long long food[50];
long long allSelected;
int n,m,ans;

void solve(int idx, long long select, int cnt) {
    if(ans <= cnt) 
        return;
    if(select == allSelected) {
        ans = min(ans, cnt);
        return;
    }
    
    for(int i=idx; i<m; ++i) {
        long long curSelect = select | food[i];
        if(curSelect > select)
            solve(idx+1, curSelect, cnt+1);
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);

        memset(food, 0, sizeof(food));
        names.resize(n);
        allSelected = ((1<<n) - 1);
        ans = INF;

        for(int i=0; i<n; ++i) {
           char name[11];
           scanf(" %s", name);
           names[i] = name;
        }
        sort(names.begin(), names.end());

        for(int i=0; i<m; ++i) {
            int num;
            scanf("%d", &num);
            for(int j=0; j<num; ++j) {
                char name[11];
                scanf(" %s", name);
                food[i] |= (1<<(lower_bound(names.begin(), names.end(), name)-names.begin()));
            }
        }
        solve(0, 0, 0);
        printf("%d\n", ans);
    }
}