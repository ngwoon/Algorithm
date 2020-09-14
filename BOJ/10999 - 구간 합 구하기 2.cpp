#include <bits/stdc++.h>
using namespace std;

vector<long long> num;
vector<long long> tree;
vector<long long> lazy;

long long init(int start, int end, int tidx) {
    if(start == end)
        return tree[tidx] = num[start];
    
    int mid = (start + end) / 2;
    return tree[tidx] = init(start, mid, tidx*2) + init(mid+1, end, tidx*2+1);
}

void updateLazy(int start, int end, int tidx) {
    if(lazy[tidx] != 0) {
        tree[tidx] += (end-start+1)*lazy[tidx];
        if(start != end) {
            lazy[tidx*2] += lazy[tidx];
            lazy[tidx*2+1] += lazy[tidx];
        }
        lazy[tidx] = 0;
    }
}

long long query(int start, int end, int tidx, int left, int right) {
    updateLazy(start, end, tidx);

    if(start > right || end < left)
        return 0;
    if(start >= left && end <= right)
        return tree[tidx];
    
    int mid = (start + end) / 2;
    return query(start, mid, tidx*2, left, right) + query(mid+1, end, tidx*2+1, left, right);
}

void update(int start, int end, int tidx, long long diff, int left, int right) {
    updateLazy(start, end, tidx);

    if(start > right || end < left)
        return;
    if(start >= left && end <= right) {
        tree[tidx] += (end-start+1) * diff;
        if(start != end) {
            lazy[tidx*2] += diff;
            lazy[tidx*2+1] += diff;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    update(start, mid, tidx*2, diff, left, right);
    update(mid+1, end, tidx*2+1, diff, left, right);
    tree[tidx] = tree[tidx*2] + tree[tidx*2+1];
}

int main(void) {
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    num.resize(n+1);
    tree.resize(n*4, 0);
    lazy.resize(n*4, 0);
    for(int i=1; i<=n; ++i)
        scanf("%lld", &num[i]);

    init(1, n, 1);
    for(int i=0; i<m+k; ++i) {
        int a,b,c;
        scanf("%d", &a);

        if(a == 1) {
            long long d;
            scanf("%d %d %lld", &b, &c, &d);
            update(1, n, 1, d, b, c);
        } else {
            scanf("%d %d", &b, &c);
            printf("%lld\n", query(1, n, 1, b, c));
        }
    }
}