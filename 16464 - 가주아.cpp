#include <bits/stdc++.h>
using namespace std;

/*
    16464번 - 가주아

    연속된 수의 합으로 주어진 정수 K를 만들 수 있는지 묻는 문제

    연속된 수의 합에 대한 알고리즘을 검색하여 찾아보았다.

    1. 주어진 수 K에서 1,2를 뺀다.
    2. K가 2로 나누어 떨어지고, 이 때의 몫이 I 라면 (1+I) + (2+I) 의 연속된 수의 합이 성립한다.
    3. 만약 나누어 떨어지지 않았다면, K에 3을 뺀다.
    4. K가 3으로 나누어 떨어지고 이 때의 몫이 Q 라면 (1+Q) + (2+Q) + (3+Q) 의 연속된 수의 합이 성립한다.

    ....

    위 과정을 K가 0보다 크거나 같을 때까지 게속한다.
*/

string ans;

int main(void) {
    int t,n;
    scanf("%d", &t);

    for(int z=0; z<t; ++z) {
        scanf(" %d", &n);

        if(n % 2 == 1) { ans.append("Gazua\n"); continue; }
        
        int seq=2;
        n -= 1;
        while(1) {
            n -= seq;
            if(n < 0) { ans.append("GoHanGang\n"); break; }
            if(n % seq == 0) { ans.append("Gazua\n"); break; }
            ++seq;
        }
    }
    printf("%s", ans.c_str());
}