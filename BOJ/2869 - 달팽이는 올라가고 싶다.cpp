#include <bits/stdc++.h>
using namespace std;

/*
    2869번 - 달팽이는 올라가고 싶다.

    입력이 크기 때문에 TLE가 발생할 수 있다.

    정상까지 도달하는 데 걸리는 일 수를 mid로 두고, 이분탐색을 이용하여 풀 수 있다.
    단, while문 내에서 현재 mid일 만에 정상에 도달할 수 있는지 계산하는 부분에서, overflow가 날 수 있음을
    인지하지 못해 틀렸다.

    브론즈 문제이지만 기본적인 TLE나 overflow를 살펴봐야 한다는 주의를 주는 문제.
*/

int ans;

int main(void) {
    int a,b,v;
    scanf("%d %d %d", &a, &b, &v);

    int low=1, high=1000000000;
    int oneday = a-b;
    while(low <= high) {
        long long mid = (low + high)/2;

        long long cost = (long long)oneday * (mid-1) + a;
        if(cost >= v) {
            high = mid - 1; ans = mid;
        }
        else low = mid + 1;
    }

    printf("%d", ans);
}