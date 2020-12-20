#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    
    vector<int> nums(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &nums[i]);
    
    for(int i=0; i<n-1; ++i) {
        for(int j=i; j<n; ++j) {
            if(nums[i] > nums[j]) {
                nums[i] ^= nums[j];
                nums[j] ^= nums[i];
                nums[i] ^= nums[j];
            }
        }
    }

    for(int i=0; i<n; ++i)
        printf("%d\n", nums[i]);
}