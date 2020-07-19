#include <bits/stdc++.h>
using namespace std;

struct medal {
    int country, gold, silver, bronze;
    
    bool operator!=(const struct medal& a) const {
        if(this->gold != a.gold || this->silver != a.silver || this->bronze != a.bronze)
            return true;
        else
            return false;
    }
};

struct medal score[1000];

bool cmp (const struct medal& a, const struct medal& b) {
    if(a.gold < b.gold)
        return true;
    else if(a.gold > b.gold)
        return false;
    else {
        if(a.silver < b.silver)
            return true;
        else if(a.silver > b.silver)
            return false;
        else {
            if(a.bronze < b.bronze) 
                return true;
            else
                return false;
        }
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i) {
        int c, g, s, b;
        scanf("%d %d %d %d", &c, &g, &s, &b);
        score[i] = {c,g,s,b};
    }

    sort(score, score+n, cmp);

    printf("\n");
    for(int i=0; i<n; ++i) {
        printf("%d %d %d %d\n", score[i].country, score[i].gold, score[i].silver, score[i].bronze);
    }
    printf("\n");

    int idx=1;
    if(k != score[n-1].country) {
        for(int i=n-2; i>=0; --i) {
            if(score[i] != score[i+1])
                idx = n - i;
            if(score[i].country == k)
                break;
        }
    }
    printf("%d", idx);
}