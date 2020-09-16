#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<long long> tree;

long long init(int start, int end, int tidx) {
    if(start == end)
        return tree[tidx] = num[start];
    int mid = (start + end) / 2;
    return tree[tidx] = init(start, mid, tidx*2) + init(mid+1, end, tidx*2+1);
}

long long query(int start, int end, int tidx, int left, int right) {
    if(start > right || end < left)
        return 0;
    if(left <= start && end <= right)
        return tree[tidx];
    
    int mid = (start + end) / 2;
    return query(start, mid, tidx*2, left, right) + query(mid+1, end, tidx*2+1, left, right);
}

void update(int start, int end, int tidx, int idx, int val) {
    if(start > idx || end < idx)
        return;
    if(start == end) {
        tree[tidx] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, tidx*2, idx, val);
    update(mid+1, end, tidx*2+1, idx, val);
    tree[tidx] = tree[tidx*2] + tree[tidx*2+1];
}

int main(void) {
    int n,q;
    scanf("%d %d", &n, &q);

    num.resize(n+1);
    tree.resize(n*4);
    for(int i=1; i<=n; ++i)
        scanf("%d", &num[i]);

    init(1, n, 1);
    for(int i=0; i<q; ++i) {
        int x,y,a,b;
        scanf("%d %d %d %d", &x, &y, &a, &b);

        printf("%lld\n", x <= y ? query(1, n, 1, x, y) : query(1, n, 1, y, x));
        update(1, n, 1, a, b);
    }
}