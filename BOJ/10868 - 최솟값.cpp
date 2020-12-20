#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001

vector<int> num;
vector<int> tree;

int init(int start, int end, int tidx) {
    if(start == end)
        return tree[tidx] = num[start];

    int mid = (start + end) / 2;
    return tree[tidx] = min(init(start, mid, tidx*2), init(mid+1, end, tidx*2+1));
}

int query(int start, int end, int tidx, int left, int right) {
    if(end < left || start > right)
        return INF;
    if(start >= left && end <= right)
        return tree[tidx];

    int mid = (start + end) / 2;
    return min(query(start, mid, tidx*2, left, right), query(mid+1, end, tidx*2+1, left, right));
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    num.resize(n+1);
    for(int i=1; i<=n; ++i)
        scanf("%d", &num[i]);
    
    tree.resize(n*4);

    init(1, n, 1);

    for(int i=0; i<m; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);

        printf("%d\n", query(1, n, 1, a, b));
    }
}