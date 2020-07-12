#include <bits/stdc++.h>
using namespace std;

vector<int> weight;

int main(void) {
    int n;
    scanf("%d", &n);

    weight.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &weight[i]);
    
    sort(weight.begin(), weight.end());

    int answer=1;
    for(int w : weight) {
        if(answer < w) break;
        answer += w;
    }
    printf("%d", answer);
}