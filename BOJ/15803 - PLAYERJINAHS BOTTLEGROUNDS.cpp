#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pos;

int main(void) {
    pos.resize(3);
    for(int i=0; i<3; ++i) scanf(" %d %d", &pos[i].first, &pos[i].second);
    
    sort(pos.begin(), pos.end());

    int xgap1 = pos[1].first - pos[0].first;
    int xgap2 = pos[2].first - pos[1].first;
    int ygap1 = pos[1].second - pos[0].second;
    int ygap2 = pos[2].second - pos[1].second;

    if((pos[0].first == pos[1].first && pos[1].first == pos[2].first) || (pos[0].second == pos[1].second && pos[1].second == pos[2].second))
        printf("WHERE IS MY CHICKEN?");
    else if(ygap1 * xgap2 == xgap1 * ygap2) printf("WHERE IS MY CHICKEN?");
    else printf("WINNER WINNER CHICKEN DINNER!");
}