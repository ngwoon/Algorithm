#include <bits/stdc++.h>

/*
    1002 - 터렛

    좌표평면에서의 세 점의 위치에 대한 문제.

    조건으로 주어진 두 좌표가 항상 빗변일 거라는 잘못된 생각으로 틀린 문제이다.

    생각을 좀 더 발전시키면 주어진 두 좌표와 각 좌표에서의 거리를 이용하여 두 원의 내접, 외접 문제로 생각하여 풀 수도 있다.
*/

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        int x1, x2, y1, y2, r1, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        int count;

        // 세 좌표가 삼각형을 이룰 경우
        int longest, rest1, rest2;
        if(dist >= r1 && dist >= r2) { longest = dist; rest1 = r1; rest2 = r2; }
        else if(r1 >= dist && r1 >= r2) { longest = r1; rest1 = dist; rest2 = r2; }
        else { longest = r2; rest1 = r1; rest2 = dist; }

        if((x1 != x2 || y1 != y2) && longest < rest1 + rest2) count = 2;
        // 터렛 두 좌표가 동일하고, 목표까지의 거리가 동일할 경우
        else if(x1 == x2 && y1 == y2 && r1 == r2) count = -1;
        // 터렛 두 좌표와 목표가 한 직선에 포함될 경우
        else if(dist == r1 - r2 || dist == abs(r1 - r2) || dist == r1 + r2) count = 1;
        else count = 0;

        printf("%d\n", count);
    }
}