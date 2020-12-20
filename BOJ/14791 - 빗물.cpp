#include <bits/stdc++.h>
using namespace std;

vector<int> heights;
int H,W;

int main(void) {
    scanf("%d %d", &H, &W);

    heights.resize(W+2);
    heights[0] = 0;
    heights[W+1] = 0;
    for(int i=1; i<W+1; ++i) scanf(" %d", &heights[i]);

    int ans=0;
    for(int i=1; i<W+1; ++i) {
        int leftmax = *max_element(heights.begin(), heights.begin()+i+1);
        int rightmax = *max_element(heights.begin()+i+1, heights.end());

        int minHeight = min(leftmax, rightmax);

        int raindrop = minHeight - heights[i];
        ans += raindrop < 0 ? 0 : raindrop;
    }

    printf("%d", ans);
}