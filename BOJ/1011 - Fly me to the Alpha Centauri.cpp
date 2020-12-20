#include <bits/stdc++.h>
using namespace std;

/*
    1011번 - Fly me to the Alpha Centauri

    y,x 값 자체는 중요하지 않고, y-x가 중요했던 문제.

    규칙이 떠오르지 않아서 노트에 y-x값에 따라 필요한 move 횟수를 적어 보았다.

    move 횟수가 1,2,3,3,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,8... 와 같이 증가함을 알 수 있었다.

    즉, move 횟수를 기준으로 y-x를 찾으려면, 1+1+2+2+3+3+4+4... +k+k 로 찾을 수 있다.

    예를들어, y-x 값이 10인 경우를 생각해보자.
    단순 연산을 해보면, 1+1+2+2 는 10보다 작고, 1+1+2+2+3+3은 10보다 크다.
    즉, k(k+1)이 10보다 작음을 만족하면서 가장 큰 k는 2이다.
    즉, y-x = 10일 때 걸리는 move 횟수는 5 또는 6이다. ( (k+1)*2 - 1 or (k+1)*2 )
*/

string ans;

int main(void) {
    int t;
    scanf("%d", &t);
    
    int maxGap = 0;
    for(int z=0; z<t; ++z) {
        unsigned int x, y;
        scanf(" %u %u", &x, &y);

        long long gap = y-x;

        if(gap == 1) { ans += "1\n"; continue; }
        else if(gap == 2) { ans += "2\n"; continue; }

        long long low=1, high=gap;

        long long k=1;
        while(low <= high) {
            long long mid = (low + high)/2;

            if(mid * (mid + 1) < gap) { k = k < mid ? mid : k; low = mid + 1; }
            else high = mid - 1;
        }

        long long start = k*(k+1);

        if(gap <= start + k + 1) ans += to_string((k+1)*2 - 1) + "\n";
        else ans += to_string((k+1)*2) + "\n";
    }
    printf("%s", ans.c_str());
}