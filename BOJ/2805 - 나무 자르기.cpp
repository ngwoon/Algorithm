#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long trees[1000000];

bool cmp(int a, int b) {
    return a > b;
}

int main(void) {
    int n,m;
    int ans=0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i) {
        scanf("%d", &trees[i]);
    }

    sort(trees, trees + n, cmp);

    long long low = trees[n-1];
    long long high = trees[0];
    
    while(low <= high) {
        long long mid = (low + high) / 2;
        
        long long sum = 0;
        int idx = 0;
        while(trees[idx] > mid) {
            sum += (trees[idx++] - mid);
        }

        if(sum < m) {
            high = mid - 1;
        } else {
            ans = ans > mid ? ans : mid;
            low = mid + 1;
        }
    }

    printf("%d", ans);
}