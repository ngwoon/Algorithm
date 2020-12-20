#include <bits/stdc++.h>
using namespace std;

vector<int> me;
vector<int> counter;

int main(void) {
    int n;
    scanf("%d", &n);

    me.resize(n);
    counter.resize(n);

    for(int i=0; i<n; ++i) scanf(" %d", &me[i]);
    for(int i=0; i<n; ++i) scanf(" %d", &counter[i]);

    sort(me.begin(), me.end());
    sort(counter.begin(), counter.end());

    int score=0;
    for(int i=0; i<n; ++i) {
        vector<int>::iterator iter = upper_bound(counter.begin(), counter.end(), me[i]);
        if(iter == counter.end()) break;
        else {
            counter.erase(iter);
            ++score;
        }
    }
    if(score >= n/2+1) printf("YES");
    else printf("NO");
}