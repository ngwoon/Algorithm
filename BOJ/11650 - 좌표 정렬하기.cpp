#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> pos(n);
    for(int i=0; i<n; ++i)
        scanf("%d %d", &pos[i].first, &pos[i].second);
    
    sort(pos.begin(), pos.end());

    for(int i=0; i<n; ++i)
        printf("%d %d\n", pos[i].first, pos[i].second);
}