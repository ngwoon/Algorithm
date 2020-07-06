#include <bits/stdc++.h>
using namespace std;

vector<int> longest;
int seq[1000001];
int n;

int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &seq[i]);

    longest.push_back(-10000000001);
    for(int i=1; i<=n; ++i) {
        if(longest.back() < seq[i])
            longest.push_back(seq[i]);
        else if(longest.back() > seq[i])
            *lower_bound(longest.begin(), longest.end(), seq[i]) = seq[i];
    }

    printf("%d", longest.size() - 1);
}