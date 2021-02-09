#include <bits/stdc++.h>
using namespace std;

int field[50][50];
int n, m, ans = 987654321;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<pair<int, int>> notClose;

void dfs(int idx, int cCount) {
    
    if(cCount == m) {
        int sum=0;
        for(int i=0; i<houses.size(); ++i) {
            int hy = houses[i].first;
            int hx = houses[i].second;
            int shortcut = 100;
            for(int j=0; j<notClose.size(); ++j) {
                int dst = abs(hy - notClose[j].first) + abs(hx - notClose[j].second);
                if(shortcut > dst)
                    shortcut = dst;
            }

            sum += shortcut;
        }

        if(ans > sum)
            ans = sum;
        
        return;
    }

    if(idx >= chickens.size())
        return;

    for(int i=idx; i<chickens.size(); ++i) {
        notClose[cCount] = chickens[i];
        dfs(i+1, cCount+1);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            scanf("%d", &field[i][j]);
            
            if(field[i][j] == 1)
                houses.push_back({i, j});
            else if(field[i][j] == 2)
                chickens.push_back({i, j});
        }
    }

    notClose.resize(m);
    dfs(0, 0);

    printf("%d", ans);
}