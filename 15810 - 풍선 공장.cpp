#include <bits/stdc++.h>
using namespace std;

vector<int> mins;
int N, M;
long long ans=0;

int main(void) {
    scanf("%d %d", &N, &M);

    mins.resize(N);
    for(int i=0; i<N; ++i)
        scanf(" %d", &mins[i]);

    long long low = 0;
    long long high = 1000000000001LL;
    while(low <= high) {
        long long mid = (low + high) / 2;

        long long sum=0;
        for(int i=0; i<N; ++i) sum += (mid / mins[i]);

        if(sum >= M) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    printf("%lld", ans);
}