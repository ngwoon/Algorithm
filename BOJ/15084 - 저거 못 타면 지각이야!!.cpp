#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> bus;
vector<int> station;
int n,m;

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; ++i) {
        pair<int, int> b;
        scanf(" %d %d", &b.first, &b.second);
        bus.push(b);
    }

    station.resize(n,-1);
    int timer=0;
    while(++timer) {
        for(int i=0; i<station.size(); ++i) {
            if(station[i] != -1 && station[i] != 0) --station[i];
        }

        for(int i=0; i<station.size(); ++i) {
            if(station[i] == 0 || station[i] == -1) station[i] = -1;
            else break;
        }

        // 정류장이 비어 있을 때 버스가 때맞춰 오거나, 정류장이 비어서 밖에서 대기중인 버스가 정류장에 들어옴
        while(!bus.empty()) {
            if(station[n-1] != -1) break;
            if(bus.front().first <= timer) {
                int i;
                for(i=n-1; i>=0; --i) {
                    if(station[i] != -1) { station[i+1] = bus.front().second; bus.pop(); break; }
                }
                if(i == -1) { station[0] = bus.front().second; bus.pop(); }
            }
            else break;
        }

        if(bus.empty()) {
            for(int i=n-1; i>=0; --i) {
                if(station[i] != -1) { printf("%d", i+1); exit(0); }
            }
        }
    }
}
