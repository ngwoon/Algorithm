#include <bits/stdc++.h>
using namespace std;

struct bus_route {
    int s, e, num;

    bus_route(int num, int s, int e): s(s), e(e), num(num) {}

    bool operator < (struct bus_route& a) {
        if(this->s == a.s)
            return this->e > a.e;
        return this->s < a.s;   
    }
};

bool comp(struct bus_route& a, struct bus_route& b) {
    return a.num < b.num;
}

vector<struct bus_route> route;
int n,m;

int main(void) {
    scanf("%d %d", &n, &m);

    int maxEnd=0;
    for(int i=1; i<=m; ++i) {
        int s,e;
        scanf("%d %d", &s, &e);
        if(s < e)
            route.push_back({i, s, e});
        else {
            maxEnd = max(maxEnd, e);
            route.push_back({i, s, e+n});
        }
    }

    sort(route.begin(), route.end());

    deque<struct bus_route> ans;
    // A 그룹 내에서, 혹은 B 그룹 내에서 포함되는 노선 거르기
    for(int i=0; i<route.size(); ++i) {
        if(ans.empty() || route[i].e > ans.back().e)
            ans.push_back(route[i]);
    }

    // A 그룹 중 B 그룹의 노선에 포함되는 노선들 거르기
    while(!ans.empty() && ans.front().e <= maxEnd)
        ans.pop_front();

    sort(ans.begin(), ans.end(), comp);
    for(int i=0; i<ans.size(); ++i)
        printf("%d ", ans[i].num);
}