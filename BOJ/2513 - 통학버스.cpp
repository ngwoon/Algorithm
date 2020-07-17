#include <bits/stdc++.h>
using namespace std;

pair<int, int> apart[30000];

int main(void) {
    int n,k,s;
    scanf("%d %d %d", &n, &k, &s);

    for(int i=0; i<n; ++i) {
        scanf("%d", &apart[i].first);
        scanf("%d", &apart[i].second);
    }

    sort(apart, apart+n);

    stack<pair<int, int>> stk[2], temp;

    for(int i=0; i<n; ++i) {
        if(apart[i].first < s)
            temp.push(apart[i]);
        else
            stk[1].push(apart[i]);
    }

    while(!temp.empty()) {
        stk[0].push(temp.top());
        temp.pop();
    }

    long long dst = 0;
    for(int i=0; i<2; ++i) {
        while(!stk[i].empty()) {
            dst += (abs(s - stk[i].top().first) << 1);
            int student = 0;
            while(!stk[i].empty()) {
                if(student + stk[i].top().second <= k) {
                    student += stk[i].top().second;
                    stk[i].pop(); 
                }
                else {
                    if(k != student) {
                        stk[i].top().second -= (k-student);
                        student = k;
                    }
                    break;
                }
            }
        }
    }

    printf("%lld", dst);
}