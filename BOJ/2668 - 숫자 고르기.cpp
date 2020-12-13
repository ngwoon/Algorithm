#include <bits/stdc++.h>
using namespace std;

vector<int> adj; 
vector<bool> ans;

int main(void) {
    cin.sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);

    adj.resize(n+1);
    for(int i=1; i<=n; ++i)
        scanf("%d", &adj[i]);

    ans.resize(n+1, false);
    for(int i=1; i<=n; ++i) {

        if(ans[i])
            continue;

        vector<bool> visited;
        visited.resize(n+1, false);
        int cur = i;
        while(1) {
            visited[cur] = true;
            int next = adj[cur];
            if(visited[next]) {
                if(next == i) {
                    for(int j=1; j<=n; ++j) {
                        if(visited[j])
                            ans[j] = true;
                    }
                }
                break;
            }
            cur = next;
        }
    }

    string str;
    int cnt = 0;
    for(int i=1; i<=n; ++i) {
        if(ans[i]) {
            ++cnt;
            str.append(to_string(i)+"\n");
        }
    }

    printf("%d\n", cnt);
    printf("%s", str.c_str());
}