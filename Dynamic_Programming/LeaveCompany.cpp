#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

/*
    백준 14501번 - 퇴사

    N이 작아 브루트 포스로도 해결 가능한 문제
*/

int N;
pair<int, int> list[16];

int solve(int day, int cost) {
    
    int result = cost;
    for(int i=day + 1; i<N+1; i++) {
        if(i < day + list[day].first) continue;
        if(list[i].first + i - 1 > N) continue;

        result = max(solve(i, cost + list[i].second), result);
    }
    return result;
}

int main(void) {
    scanf("%d", &N);

    for(int i=1; i<N+1; i++) {
        int days, cost;
        scanf(" %d %d", &days, &cost);
        list[i] = {days, cost};
    }

    list[0].first = 0;
    list[0].second = 0;

    printf("%d",solve(0,0));
}