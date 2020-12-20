#include <bits/stdc++.h>
using namespace std;

vector<int> cards;
vector<int> cases;
int younghak[2];

int main(void) {
    scanf("%d %d", &younghak[0], &younghak[1]);
    cards.resize(20);
    int index=0;
    
    for(int i=0; i<10; ++i) { cards[i*2] = i+1; cards[i*2+1] = i+1; }

    for(int i=0; i<2; ++i)
        cards.erase(find(cards.begin(), cards.end(), younghak[i]));

    cases.resize(20);
    for(int i=0; i<17; ++i) {
        for(int j=i+1; j<18; ++j) {
            if(cards[i] == cards[j]) ++cases[cards[i] + 9];
            else {
                int val = (cards[i] + cards[j]) % 10;
                ++cases[val];
            }
        }
    }

    int total=0;
    for(int i=0; i<20; ++i) total += cases[i];

    double ans;
    if(younghak[0] == younghak[1]) {
        double lose=0;
        for(int i=younghak[0] + 10; i<20; ++i) lose += cases[i];
        ans = 1 - lose/total;
   } else {
       double win=0;
       int cardVal = (younghak[0] + younghak[1]) % 10;
       for(int i=0; i<cardVal; ++i) win += cases[i];
       ans = win/total;
   }
   printf("%.3lf", ans);
}