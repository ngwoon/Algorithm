/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;

int n,k,m,ans;
int start, dest;
int dp[1501][1501];
vector<pair<int, int>> adj[1501];

void dfs(int cur, int depth, int del) {
    if(depth == k) {
        if(dp[start][cur] == -2)
            dp[start][cur] = del;
        else
            dp[start][cur] = min(dp[start][cur], del);
        return;
    }

    int cnt=0;
    for(int i=0; i<adj[cur].size(); ++i) {
        if(adj[cur][i].first <= depth)
            continue;

        int next = adj[cur][i].second;
        int ndepth = adj[cur][i].first;

        dfs(next, ndepth, del + cnt);
        ++cnt;
    }
    if(cnt == 0)
        dfs(cur, k, del);
    else
        dfs(cur, k, del + cnt);
}

int main(int argc, char** argv)
{
	int T, test_case;
    setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
        scanf("%d %d %d", &n, &k, &m);

        for(int i=1; i<=n; ++i)
            adj[i].resize(0);
        
        for(int i=0; i<k; ++i) {
            int a,b;
            scanf("%d %d", &a, &b);
            adj[a].push_back({i+1, b});
            adj[b].push_back({i+1, a});
        }

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j)
                dp[i][j] = -2;
        }
        
        ans = 0;
        for(int i=0; i<m; ++i) {
            scanf("%d %d", &start, &dest);

            if(dp[start][dest] == -2) {
                dfs(start, 0, 0);
                for(int j=1; j<=n; ++j) {
                    if(dp[start][j] == -2) {
                        dp[start][j] = -1;
                    }
                }
            }
            
            ans += dp[start][dest];
        }

		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case+1);
		printf("%d\n", ans);
	}

	return 0;//Your program should return 0 on normal termination.
}