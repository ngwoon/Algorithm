#include <bits/stdc++.h>
using namespace std;

vector<long long> num;
vector<long long> tree;

long long init(int start, int end, int tindex) {
    if(start == end)
        return tree[tindex] = num[start];
    
    int mid = (start + end) / 2;
    return tree[tindex] = init(start, mid, tindex*2) + init(mid+1, end, tindex*2+1);
}

void update(int start, int end, int tindex, int chIdx, long long chVal) {
    if(start > chIdx || chIdx > end)
        return;
            
    tree[tindex] += chVal - num[chIdx];

    if(start != end) {
        int mid = (start + end) / 2;
        update(start, mid, tindex*2, chIdx, chVal);
        update(mid+1, end, tindex*2+1, chIdx, chVal);
    }
}

long long getSum(int start, int end, int tindex, int left, int right) {
    if(start > right || end < left)
        return 0;
    if(start >= left && end <= right)
        return tree[tindex];
    else {
        int mid = (start + end) / 2;
        return getSum(start, mid, tindex*2, left, right) + getSum(mid+1, end, tindex*2+1, left, right);
    }
}

int main(void) {
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    num.resize(n+1);
    for(int i=1; i<=n; ++i)
        scanf("%lld", &num[i]);

    tree.resize(n*4 + 4);
    init(1, n, 1);

    for(int i=0; i<m+k; ++i) {
        int a,b;
        long long c;
        scanf("%d %d %lld", &a, &b, &c);

        if(a == 1) {
            update(1, n, 1, b, c);
            num[b] = c;
        } else {
            printf("%lld\n", getSum(1, n, 1, b, c));
        }
    }
    
}