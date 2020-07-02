#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> info; // 첫번째 : 부모, 두번째 : 병사 수 (최상단 노드가 아니면 -1)

int Find(int x) {
    if(info[x].first == x) return x;
    else return info[x].first = Find(info[x].first);
}

void Union(int x, int y, int o) {
    x = Find(x);
    y = Find(y);
    if(x != y) {
        if(o == 1) {
            info[x].second += info[y].second;
            //info[y].second = -1;
            info[y].first = x;
        } else {
            int b,s;
            b = info[x].second >= info[y].second ? x : y;
            s = b == x ? y: x;
            
            if(info[b].second == info[s].second) {
                info[b].first = 0;
                info[s].first = 0;
            } else {
                info[b].second -= info[s].second;
                //info[s].second = -1;
                info[s].first = b;
            }
        }
    }
}

int main(void) {
    int N, R;
    scanf("%d %d", &N, &R);

    info.resize(N+1, {0,0});
    for(int i=1; i<=N; ++i) scanf(" %d", &info[i].second);

    for(int i=1; i<=N; ++i) info[i].first = i;

    for(int i=0; i<R; ++i) {
        int o,p,q;
        scanf(" %d %d %d", &o, &p, &q);
        Union(p, q, o);
    }

    vector<int> nations;
    vector<int> military;
    for(int i=1; i<=N; ++i) {
        int nation = Find(i);
        if(nation == 0) continue;
        if(find(nations.begin(), nations.end(), nation) == nations.end()) { nations.push_back(nation); military.push_back(info[nation].second); }
    }

    sort(military.begin(), military.end());
    printf("%d\n", nations.size());
    for(int i=0; i<military.size(); ++i) printf("%d ", military[i]);

}