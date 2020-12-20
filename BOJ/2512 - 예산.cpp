#include <bits/stdc++.h>
using namespace std;

/*
    모든 지방 예산을 감소시켜야 하는 경우도 고려해야함
    따라서 low 시작을 0부터 해야한다.
*/          

int prov[10000];

int main(void) {
    int n, m;
    scanf("%d", &n);
    
    int sum=0;
    for(int i=0; i<n; ++i) {
        scanf("%d", &prov[i]);
        sum += prov[i];
    }

    sort(prov, prov+n);

    scanf("%d", &m);

    if(sum <= m) printf("%d", prov[n-1]);
    else {
        int high=prov[n-1], low=0;
        int ans=0;
        while(low <= high) {
            int mid = (high + low) / 2;

            sum=0;
            for(int i=0; i<n; ++i) {
                if(prov[i] > mid)
                    sum += mid;
                else
                    sum += prov[i];
            }
            if(sum <= m) {
                low = mid + 1;
                ans = mid;
            }
            else
                high = mid - 1;
        }
        printf("%d", ans);
    }
}