#include <bits/stdc++.h>
using namespace std;

int n,m;
priority_queue<long long, vector<long long>, greater<long long>> cards;

int main(void) {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; ++i) { 
        long long val;
        scanf(" %lld", &val);
        cards.push(val);
    }

    while(m--) {
        long long sum = 0;
        sum += cards.top(); cards.pop();
        sum += cards.top(); cards.pop();
        cards.push(sum); cards.push(sum);
    }

    long long sum = 0;
    while(!cards.empty()) {
        sum += cards.top();
        cards.pop();
    }

    printf("%lld", sum);
}