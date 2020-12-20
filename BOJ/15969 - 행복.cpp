#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    vector<int> scores(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &scores[i]);

    sort(scores.begin(), scores.end());

    printf("%d", scores.back() - scores[0]);
}