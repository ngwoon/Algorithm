#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int,int>> indices;
vector<int> a;
vector<int> tree;

void update(int start, int end, int tidx, int bidx) {
    if(end < bidx || bidx < start)
        return;
    if(start <= bidx && bidx <= end)
        tree[tidx] += 1;
    if(start != end) {
        int mid = (start + end) / 2;
        update(start, mid, tidx*2, bidx);
        update(mid+1, end, tidx*2+1, bidx);
        tree[tidx] = tree[tidx*2] + tree[tidx*2+1];
    }
}

int query(int start, int end, int tidx, int left, int right) {
    if(start > right || end < left)
        return 0;
    if(left <= start && end <= right)
        return tree[tidx];
    
    int mid = (start + end) / 2;
    return query(start, mid, tidx*2, left, right) + query(mid+1, end, tidx*2+1, left ,right);
}

int main(void) {
    int n;
    scanf("%d", &n);

    a.resize(n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &a[i]);
        indices.insert({a[i], {i, 0}});
    }
    for(int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        indices[num].second = i; 
    }

    tree.resize(n*4, 0);
    long long ans=0;
    for(int i=0; i<n; ++i) {
        int bidx = indices[a[i]].second;
        ans += query(0, n-1, 1, bidx+1, n-1);
        update(0, n-1, 1, bidx);
    }
    printf("%lld", ans);
}