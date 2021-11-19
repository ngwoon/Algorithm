#include <bits/stdc++.h>
using namespace std;

int cnt[8001];
vector<int> nums;

int main(void) {
    int n;
    scanf("%d", &n);

    nums.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &nums[i]);

    sort(nums.begin(), nums.end());

    double sum=0;
    for(int i=0; i<n; ++i) {
        sum += nums[i];
        ++cnt[nums[i] + 4000];
    }
    
    int mean = round(sum / n);
    int middle = nums[n/2];
    int freq = 0;
    int freqVal = 0;
    int sameCnt = 1;
    for(int i=nums[0]; i<=nums[n-1]; ++i) {
        int idx = i + 4000;
        
        if(freq < cnt[idx]) {
            freq = cnt[idx];
            freqVal = i;
            sameCnt = 1;
        } else if(freq == cnt[idx]) {
            if(sameCnt < 2) {
                freqVal = i;
                ++sameCnt;
            }
        }
    }
    int gap = nums[n-1] - nums[0];

    printf("%d\n%d\n%d\n%d", mean, middle, freqVal, gap);
}