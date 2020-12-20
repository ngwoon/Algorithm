#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

void mergeSort(int start, int end) {
    if(start == end)
        return;
    
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid+1, end);

    vector<int> sorted(end-start+1);

    int i=start, j=mid+1, idx=0;
    while(i <= mid && j <= end) {
        if(nums[i] <= nums[j])
            sorted[idx++] = nums[i++];
        else if(nums[j] < nums[i])
            sorted[idx++] = nums[j++];
    }
    if(i <= mid) {
        while(i <= mid)
            sorted[idx++] = nums[i++];
    } else if(j <= end) {
        while(j <= end)
            sorted[idx++] = nums[j++];
    }

    idx=0;
    for(i=start; i<=end; ++i)
        nums[i] = sorted[idx++];
}

int main(void) {
    int n;
    scanf("%d", &n);

    nums.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &nums[i]);
    
    mergeSort(0, n-1);

    for(int i=0; i<n; ++i)
        printf("%d\n", nums[i]);
}