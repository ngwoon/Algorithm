#include <bits/stdc++.h>
using namespace std;

vector<int> range;
vector<int> ans;
int m;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m;
    double oneSec = 1/(double)m + 0.0000000001;

    ans.resize(m, 0);
    range.resize(m+2, 0);
    range[0] = 0; range[m+1] = 1;

    for(int i=1; i<=m; ++i) {
        range[i] = i*oneSec*1000000;
        if((i*1000000) % m) ++range[i];
    }

    double input;
    while(cin >> input) {
        double trans = (input + 0.0000000001) * 1000000;
        for(int i=0; i<=m; ++i) {
            if(range[i] <= trans && range[i+1] > trans) { ++ans[i]; break; }
        }
    }

    for(int i=0; i<m; ++i) cout << ans[i] << " ";
}