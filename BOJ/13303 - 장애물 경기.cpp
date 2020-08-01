#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> obs;
int fx, fy;

int main(void) {
    int n;
    scanf("%d %d %d", &n, &fx, &fy);

    for(int i=0; i<n; ++i) {
        int x, yl, yh;
        scanf("%d %d %d", &x, &yl, &yh);
        obs.insert({yl, x}); obs.insert({yh, x});
    }

    vector<pair<int, int>> m1, m2;
}