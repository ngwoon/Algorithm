#include <bits/stdc++.h>
using namespace std;

vector<int> market;
int N;

int main(void) {
    scanf("%d", &N);
    market.resize(N);

    for(int i=0; i<N; ++i) scanf(" %d", &market[i]);

    int milk=0;
    int cnt=0;
    for(int i=0; i<N; ++i) {
        if(market[i] == milk) { ++cnt; milk = (milk+1)%3; }
    }
    printf("%d", cnt);
}