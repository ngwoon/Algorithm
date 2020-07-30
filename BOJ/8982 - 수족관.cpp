#include <bits/stdc++.h>
using namespace std;

vector<int> sink;
vector<int> startHeight;
vector<int> height;
int horiz;

int main(void) {
    int n;
    scanf("%d", &n);

    pair<int, int> post = {0,0};
    pair<int, int> cur;
    for(int i=0; i<n; ++i) {
        scanf("%d %d", &cur.first, &cur.second);
        // 수평선분
        if(cur.first != post.first) {
            for(int j=post.first; j<cur.first; ++j)
                height.push_back(post.second);
        }
        post = cur;
    }
    startHeight.resize(height.size(), 0);

    int s;
    scanf("%d", &s);
    for(int i=0; i<s; ++i) {
        int sx,sy,ex,ey;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        sink.push_back(sx);
    }

    horiz = height.size();
    for(int i=0; i<sink.size(); ++i) {
        int h = height[sink[i]];
        startHeight[sink[i]] = h;
        // 좌 갱신
        for(int j=sink[i]-1; j>=0; --j) {
            if(h > height[j])
                h = height[j];
            if(h > startHeight[j])
                startHeight[j] = h;
            
        }

        // 우 갱신
        h = height[sink[i]];    
        for(int j=sink[i]+1; j<horiz; ++j) {
            if(h > height[j])
                h = height[j];
            if(h > startHeight[j])
                startHeight[j] = h;
        }
    }

    int ans=0;
    for(int i=0; i<horiz; ++i)
        ans += height[i] - startHeight[i];

    printf("%d", ans);
}