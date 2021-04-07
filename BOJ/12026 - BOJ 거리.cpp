// #include <bits/stdc++.h>
// using namespace std;

// int n;
// char str[1001];
// vector<vector<pair<int, int>>> adj;
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// int dst[1001];

// void bfs() {
//     pq.push({0, 0});

//     while(!pq.empty()) {
//         int cur = pq.top().second;
//         int psum = pq.top().first;
//         pq.pop();

//         for(int i=0; i<adj[cur].size(); ++i) {
//             int next = adj[cur][i].first;
//             int cost = adj[cur][i].second;
//             int nsum = psum + cost;
//             if(nsum >= dst[next])
//                 continue;
            
//             dst[next] = nsum;
//             pq.push({nsum, next});
//         }
//     }
// }

// int main(void) {
//     scanf("%d", &n);
//     scanf("%s", str);

//     adj.resize(n);
//     for(int i=0; i<n; ++i) {
//         char cur = str[i];
//         char next;
//         switch(cur) {
//             case 'B': next = 'O'; break;
//             case 'O': next = 'J'; break;
//             case 'J': next = 'B'; break;
//         }
//         for(int j=i+1; j<n; ++j) {
//             if(str[j] == next)
//                 adj[i].push_back({j, (j-i)*(j-i)});
//         }

//         dst[i] = INT_MAX;
//     }
//     dst[0] = 0;

//     bfs();

//     if(dst[n-1] == INT_MAX)
//         printf("-1");
//     else
//         printf("%d", dst[n-1]);
// }

#include <bits/stdc++.h>
using namespace std;
#define MAX 2100000000

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; ++i) {
        char temp;
        scanf(" %c", &temp);
        switch(temp) {
            case 'B': arr[i] = 0; break;
            case 'O': arr[i] = 1; break;
            case 'J': arr[i] = 2; break;
        }
    }

    int dp[n];
    for(int i=1; i<n; ++i)
        dp[i] = MAX;
    dp[0] = 0;

    for(int i=1; i<n; ++i) {
        for(int j=i-1; j>=0; --j) {
            int cost = (i-j) * (i-j);
            if(((arr[j] + 1) % 3 == arr[i]) && (dp[j] + cost < dp[i]))
                dp[i] = dp[j] + cost;
        }
    }

    for(int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    for(int i=0; i<n; ++i)
        printf("%d ", dp[i]);
    printf("\n");

    printf("%d", dp[n-1] == MAX ? -1 : dp[n-1]);
}