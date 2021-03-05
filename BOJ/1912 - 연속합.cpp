#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<int> cache;

int main(void) {
    int n;
    scanf("%d", &n);

    nums.resize(n);
    cache.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &nums[i]);

    cache[0] = nums[0];
    for(int i=1; i<n; ++i) {
        if(cache[i-1] <= 0)
            cache[i] = nums[i];
        else
            cache[i] = cache[i-1] + nums[i];
    }

    int ans=-1001;
    for(int i=0; i<n; ++i)
        ans = cache[i] > ans ? cache[i] : ans;
    
    printf("%d", ans);
}