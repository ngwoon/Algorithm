#include <bits/stdc++.h>
using namespace std;

char names[9][10] = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
int N;

int main(void) {
    scanf("%d", &N);

    vector<int> candidate;
    for(int i=0; i<9; ++i) {
        int maxCnt=0;
        for(int j=0; j<N; ++j) {
            int num;
            scanf(" %d", &num);
            maxCnt = maxCnt < num ? num : maxCnt;
        }
        candidate.push_back(maxCnt);
    }

    int maxCnt=0; int index;
    for(int i=0; i<9; ++i) {
        if(maxCnt < candidate[i]) {
            maxCnt = candidate[i];
            index = i;
        } 
    }
    printf("%s", names[index]);
}