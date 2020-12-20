#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    vector<vector<int>> color(n+1);

    for(int i=0; i<n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        color[y].push_back(x);
    }

    for(int i=1; i<=n; ++i) {
        if(!color[i].empty())
            sort(color[i].begin(), color[i].end());
    }

    int sum = 0;
    for(int i=1; i<=n; ++i) {
        if(!color[i].empty()) {
            for(int j=0; j<color[i].size(); ++j) {
                if(j == 0)
                    sum += color[i][j+1] - color[i][j];
                else if(j == color[i].size()-1)
                    sum += color[i][j] - color[i][j-1];
                else
                    sum += min(color[i][j] - color[i][j-1], color[i][j+1] - color[i][j]);
            }
        }
    }
    printf("%d", sum);
}