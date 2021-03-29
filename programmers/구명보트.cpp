#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int boat=0;
    int frontIdx=0, backIdx=people.size()-1;
    while(frontIdx <= backIdx) {
        if(frontIdx != backIdx) {
            if(people[backIdx] + people[frontIdx] <= limit)
                ++frontIdx;
        }
        --backIdx;
        ++boat;
    }
    return boat;
}

int main(void) {
    int n;
    scanf("%d", &n);

    vector<int> weights(n);
    for(int i=0; i<n; ++i) {
        int weight;
        scanf("%d", &weight);
        weights[i] = weight;
    }

    int limit;
    scanf("%d", &limit);

    printf("%d", solution(weights, limit));
}