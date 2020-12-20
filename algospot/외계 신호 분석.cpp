#include <bits/stdc++.h>
using namespace std;

struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}

    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};

int main(void) {
    int c,n,k;
    scanf("%d", &c);

    while(c--) {
        scanf("%d %d", &n, &k);

        queue<int> range;
        RNG rng;
        int rangeSum = 0, ans = 0;
        for(int i=0; i<n; ++i) {
            int nextNum = rng.next();
            rangeSum += nextNum;
            range.push(nextNum);
            
            while(rangeSum > k) {
                rangeSum -= range.front();
                range.pop();
            }

            if(rangeSum == k) ++ans;
        }

        printf("%d\n", ans);
    }
}