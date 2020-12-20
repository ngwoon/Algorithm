#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> info;
int N;

int main(void) {
    scanf("%d", &N);
    info.resize(N);
    for(int i=0; i<N; ++i)
        scanf(" %d %d", &info[i].first, &info[i].second);

    long long diff=INT_MAX;
    int fa, fb;
    for(int a=1; a<=100; ++a) {
        for(int b=1; b<=100; ++b) {
            long long rss=0;
            for(int i=0; i<N; ++i) {
                int y = info[i].second;
                int x = info[i].first;

                int calc = a*x + b;
                
                rss += pow(y-calc, 2);
            }

            if(diff > rss) { diff = rss; fa = a; fb = b; }
        }
    }
    printf("%d %d", fa, fb);
}