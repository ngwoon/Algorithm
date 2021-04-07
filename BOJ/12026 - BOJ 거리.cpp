#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
int n;
char str[1001];
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dst[1001];

void bfs() {
    pq.push({0, 0});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int psum = pq.top().first;
        pq.pop();

        for(int i=0; i<adj[cur].size(); ++i) {
            int next = adj[cur][i].first;
            int cost = adj[cur][i].second;
            int nsum = psum + cost;
            if(nsum >= dst[next])
                continue;
            
            dst[next] = nsum;
            pq.push({nsum, next});
        }
    }
}

int main(void) {
    scanf("%d", &n);
    scanf("%s", str);

    adj.resize(n);
    for(int i=0; i<n; ++i) {
        char cur = str[i];
        char next;
        switch(cur) {
            case 'B': next = 'O'; break;
            case 'O': next = 'J'; break;
            case 'J': next = 'B'; break;
        }
        for(int j=i+1; j<n; ++j) {
            if(str[j] == next)
                adj[i].push_back({j, (j-i)*(j-i)});
        }

        dst[i] = INT_MAX;
    }
    dst[0] = 0;

    bfs();

    if(dst[n-1] == INT_MAX)
        printf("-1");
    else
        printf("%d", dst[n-1]);
}