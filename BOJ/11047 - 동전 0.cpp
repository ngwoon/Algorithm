#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

vector<int> coins;
int n,k;
int ans;

int main(void) {
    scanf("%d %d", &n, &k);

    coins.resize(n);
    for(int i=0; i<n; ++i) scanf(" %d", &coins[i]);

    for(int i=n-1; i>=0; --i) {
        if(k/coins[i] != 0) {
            ans += k/coins[i];
            k %= coins[i];
        }
        if(k == 0) break;
    }    

    printf("%d", ans);
}