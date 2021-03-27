#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int boat=0;
    while(!people.empty()) {
        if(people.size() != 1) {
            if(people.back() + people.front() <= limit)
                people.erase(people.begin());
        }
        people.pop_back();
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