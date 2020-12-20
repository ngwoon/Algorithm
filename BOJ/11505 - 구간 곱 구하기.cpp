#include <bits/stdc++.h>
using namespace std;

#define LIM 1000000007

vector<long long> num;
vector<long long> tree;

long long init(int start, int end, int tidx) {
    if(start == end)
        return tree[tidx] = num[start];

    int mid = (start + end) / 2;
    return tree[tidx] = init(start ,mid, tidx*2) * init(mid+1, end, tidx*2+1) % LIM;
}

void update(int start, int end, int tidx, long long chVal, int chIdx) {
    if(start > chIdx || chIdx > end)
        return;

    if(start == end)
        tree[tidx] = chVal;
    else {
        int mid = (start + end) / 2;
        update(start, mid, tidx*2, chVal, chIdx);
        update(mid+1, end, tidx*2+1, chVal, chIdx);
        tree[tidx] = tree[tidx*2] * tree[tidx*2+1] % LIM;
    }
}

long long query(int start, int end, int tidx, int left, int right) {
    if(start > right || end < left)
        return 1;
    if(left <= start && end <= right)
        return tree[tidx];
    
    int mid = (start + end) / 2;
    return query(start, mid, tidx*2, left ,right) * query(mid+1, end, tidx*2+1, left, right) % LIM;
}


int main(void) {
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    num.resize(n+1);
    for(int i=1; i<=n; ++i)
        scanf("%lld", &num[i]);
    
    tree.resize(n*4);
    init(1, n, 1);

    for(int i=0; i<m+k; ++i) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);

        if(a == 1) {
            update(1, n, 1, c, b);
            num[b] = c;
        }
        else
            printf("%lld\n", query(1, n, 1, b, c));
    }
}