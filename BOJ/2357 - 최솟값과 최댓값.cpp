#include <bits/stdc++.h>
using namespace std;

#define MIN 0
#define MAX 1000000001

vector<int> num;
vector<pair<int, int>> tree;

pair<int, int> init(int start, int end, int tidx) {
    if(start == end)
        return tree[tidx] = {num[start], num[start]};
    int mid = (start + end) / 2;
    pair<int, int> left = init(start, mid, tidx*2);
    pair<int, int> right = init(mid+1, end, tidx*2+1);
    return tree[tidx] = {max(left.first, right.first), min(left.second, right.second)};
}

pair<int, int> query(int start, int end, int tidx, int left, int right) {
    if(end < left || start > right)
        return {MIN, MAX};
    if(start >= left && end <= right)
        return tree[tidx];
    
    int mid = (start + end) / 2;
    pair<int, int> lq = query(start, mid, tidx*2, left, right);
    pair<int, int> rq = query(mid+1, end, tidx*2+1, left, right);
    return {max(lq.first, rq.first), min(lq.second, rq.second)};
}

int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);

    num.resize(n+1);
    for(int i=1; i<=n; ++i)
        scanf("%d", &num[i]);
    
    tree.resize(n*4);
    init(1, n, 1);

    for(int i=0; i<m; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        pair<int, int> res = query(1, n, 1, a, b);
        printf("%d %d\n", res.second, res.first);
    }
}