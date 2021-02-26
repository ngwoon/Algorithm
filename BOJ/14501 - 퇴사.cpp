#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> schedules;
int n, ans;

void consult(int day, int cost) {
    if(day == n) {
        ans = ans < cost ? cost : ans;
        return;
    } else if(day > n)
        return;

    consult(day + schedules[day].first, cost + schedules[day].second);
    consult(day + 1, cost);
}

int main(void) {
    scanf("%d", &n);

    schedules.resize(n);
    for(int i=0; i<n; ++i) {
        int day, cost;
        scanf("%d %d", &day, &cost);
        schedules[i] = {day,cost};
    }

    consult(0, 0);

    printf("%d", ans);
}
