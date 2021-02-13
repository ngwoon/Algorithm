#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pq;

int main(void) {
    int n;
    scanf("%d", &n);

    pq.resize(n);
    for(int i=0; i<n; ++i)
        pq[i].resize(n);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            scanf("%d", &pq[j][i]);
    }
    
    int ans;
    int cnt = n;
    while(cnt--) {
        int maxVal = -100000001;
        int maxIdx = -1;
        for(int i=0; i<n; ++i) {
            if(maxVal < pq[i].back()) {
                maxVal = pq[i].back();
                maxIdx = i;
            }
        }

        ans = maxVal;
        pq[maxIdx].pop_back();
    }
    printf("%d", ans);
}