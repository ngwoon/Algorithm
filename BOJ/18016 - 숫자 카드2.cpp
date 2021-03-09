#include <bits/stdc++.h>
using namespace std;

map<int,int> nums;

int main(void) {
    int n, m;
    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        auto iter = nums.find(num);
        if(iter != nums.end())
            ++iter->second;
        else
            nums.insert({num, 1});
    }
    
    scanf("%d", &m);
    for(int i=0; i<m; ++i) {
        int num, cnt=0;
        scanf("%d", &num);
        auto iter = nums.find(num);
        if(iter == nums.end())
            printf("0 ");
        else
            printf("%d ", iter->second);
    }
}