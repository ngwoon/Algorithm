#include <bits/stdc++.h>
using namespace std;

int upper[3000], bottom[3000];
vector<pair<long long, pair<int, int>>> edges;

bool comp(pair<long long, pair<int, int>>& a, pair<long long, pair<int, int>>& b) {
    return a.second.first < b.second.first;
}

int main(void) {
    int n,m,l;
    scanf("%d %d %d", &n, &m, &l);

    for(int i=0; i<n; ++i)
        scanf("%d", &upper[i]);
    for(int i=0; i<m; ++i)
        scanf("%d", &bottom[i]);

    int uidx=0, bidx=0;
    while(uidx < n && bidx < m) {
        edges.push_back({upper[uidx] == bottom[bidx] ? l*l : l*l + pow(upper[uidx] - bottom[bidx], 2), {upper[uidx], bottom[bidx]}});
        if(uidx == n-1 && bidx < m-1)
            ++bidx;
        else if(bidx == m-1 && uidx < n-1)
            ++uidx;
        else if(upper[uidx] <= bottom[bidx])
            ++uidx;
        else
            ++bidx;
    }
    
    sort(edges.begin(), edges.end(), comp);

    long long cost=0;
    for(int i=0; i<edges.size(); ++i) {
        long long acc=0;
        for(int j=i; j<edges.size(); ++j) {
            acc += edges[i].first;
            cost += acc;
        }
    }
    printf("%lld", cost);
}