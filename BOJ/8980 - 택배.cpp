#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> info;
int boxes[2001];
int ans;

int main(void) {
    int n, c, m;
    scanf("%d %d %d", &n, &c, &m);

    info.resize(n+1);
    for(int i=0; i<m; ++i) {
        int s,e,d;
        scanf("%d %d %d", &s, &e, &d);
        info[e].push_back({s,d});
    }
    for(int i=2; i<=n; ++i)
        sort(info[i].begin(), info[i].end());
    
    // 도착도시번호
    for(int i=2; i<=n; ++i) {
        if(!info[i].empty()) {
            for(int j=0; j<info[i].size(); ++j) {
                int maxBox = 0; // 현재 검사중인 구간에서의 박스 최댓값
                for(int k=info[i][j].first; k<i; ++k)
                    maxBox = max(maxBox, boxes[k]);
                
                int canLoad = min(info[i][j].second, c - maxBox);

                ans += canLoad;
                for(int k=info[i][j].first; k<i; ++k)
                    boxes[k] += canLoad;
            }
        }
    }

    printf("%d", ans);
}