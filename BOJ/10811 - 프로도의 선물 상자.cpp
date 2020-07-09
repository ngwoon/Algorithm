#include <bits/stdc++.h>
using namespace std;

#define INF 987654321;

int t, ans;
pair<int, int> rect[6];

int oneOnTwo(int a, int b, int c) {
    int w = max(rect[a].first, rect[b].first + rect[c].first);
    int h = rect[a].second + max(rect[b].second, rect[c].second);
    return w*h;
}

int parallel(int a, int b, int c) {
    int w = rect[a].first + rect[b].first + rect[c].first;
    int h = max(rect[a].second, max(rect[b].second, rect[c].second));
    return w*h;
}

int main(void) {
    scanf("%d", &t);
    for(int i=0; i<t; ++i) {
        ans = INF;
        for(int j=0; j<3; ++j) {
            scanf("%d %d", &rect[j].first, &rect[j].second);
            rect[j + 3].first = rect[j].second;
            rect[j + 3].second = rect[j].first;
        }
        
        for(int j=0; j<6; ++j) {
            for(int k=0; k<6; ++k) {
                for(int m=0; m<6; ++m) {
                    if(j % 3 == k % 3 || k % 3 == m % 3 || m % 3 == j % 3)
                        continue;
                    ans = min(ans, parallel(j,k,m));
                    ans = min(ans, oneOnTwo(j,k,m));
                }
            }
        }
        printf("%d\n", ans);
    }
}