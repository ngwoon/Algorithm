// #include <bits/stdc++.h>
// using namespace std;

// int cnt;

// void dfs(int cur, vector<bool>& visited, vector<vector<int>>& adj) {

//     for(int i=0; i<adj[cur].size(); ++i) {
//         int next = adj[cur][i];
//         if(visited[next]) {
//             ++cnt;
//             continue;
//         }

//         visited[next] = true;
//         dfs(next, visited, adj);
//     }
// }

// int main(void) {
//     int t;
//     scanf("%d", &t);

//     while(t--) {
//         int n;
//         scanf("%d", &n);

//         vector<vector<int>> adj(n+1);
//         for(int i=1; i<=n; ++i) {
//             int num;
//             scanf("%d", &num);
//             adj[i].push_back(num);
//         }   

//         cnt=0;
//         vector<bool> visited(n+1, false);

//         for(int i=1; i<=n; ++i) {
//             if(visited[i]) continue;
//             dfs(i, visited, adj);
//         }

//         printf("%d\n", cnt);
//     }
// }


#include <bits/stdc++.h>
using namespace std;

void search(int num, vector<int>& adj, vector<bool>& visited) {
    int cur = num;
    while(!visited[cur]) {
        visited[cur] = true;
        cur = adj[cur];
    }
}

int main(void) {
    int t,n;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        vector<int> adj;
        vector<bool> visited;
        
        int ans=0;
        adj.resize(n+1);
        visited.resize(n+1, false);
        for(int i=1; i<=n; ++i) {
            int num;
            scanf("%d", &num);
            adj[i] = num;
        }

        for(int i=1; i<=n; ++i) {
            if(!visited[i]) {
                search(i, adj, visited);
                ++ans;
            }
        }

        printf("%d\n", ans);
    }
}