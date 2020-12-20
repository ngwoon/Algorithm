#include <bits/stdc++.h>
using namespace std;

vector<int> line;

int main(void) {
    int m, n, L;
    scanf("%d %d %d", &m, &n, &L);

    line.resize(m);
    for(int i=0; i<m; ++i)
        scanf("%d", &line[i]);

    sort(line.begin(), line.end());

    int cnt=0;
    for(int i=0; i<n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);

        auto iter = lower_bound(line.begin(), line.end(), x);

        if(iter == line.end())
            iter = line.end()-1;

        if(*iter == x) {
            if(L >= y)
                ++cnt;
        } else {
            if(iter != line.begin()) {
                if(*iter - x > x - *(iter-1))
                    --iter;
            }
            
            int gap = abs(x - *iter) + y;
            if(gap <= L)
                ++cnt;
        }
    }
    printf("%d", cnt);
}