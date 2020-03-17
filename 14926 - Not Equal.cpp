#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> adj;
string ans;
int n;

void dfs(int cur) {
    ans += 'a'; ans += (char)(cur+'0'); ans += ' ';
    for(int i=1; i<=n; ++i) {
        if(adj[cur][i]) {
            int j;
            for(j=1; j<=n; ++j) {
                if(j != cur && adj[i][j]) break;
            }
            if(j == n+1) continue;

            adj[cur][i]=false; adj[i][cur]=false;
            dfs(i);
        }
    }
}

int main(void) {
    scanf("%d", &n);
    adj.resize(n+1);
    for(int i=1; i<=n; ++i) adj[i].resize(n+1, true);
    for(int i=1; i<=n; ++i) adj[i][i]=false;

    dfs(1); ans += "a1";
    printf("%s", ans.c_str());
}