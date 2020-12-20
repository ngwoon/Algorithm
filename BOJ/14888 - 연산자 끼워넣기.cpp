#include <bits/stdc++.h>
using namespace std;

/*
    14888 - 연산자 끼워넣기

    브루트 포스로 푼 문제.
*/

vector<int> seq;
int n;
int optr[4];
int comb[10];
int minVal = INT_MAX, maxVal = -INT_MAX;

void backTracking(int index) {
    if(index == n-1) {
        int calc = seq[0];
        for(int i=0; i<n; ++i) {
            switch(comb[i]) {
                case 0 : calc += seq[i+1]; break;
                case 1 : calc -= seq[i+1]; break;
                case 2 : calc *= seq[i+1]; break;
                case 3 : calc /= seq[i+1]; break;
            }
        }
        if(minVal > calc) minVal = calc;
        if(maxVal < calc) maxVal = calc;
        return;
    }

    for(int i=0; i<4; ++i) {
        if(optr[i] > 0) {
            comb[index] = i;
            --optr[i];
            backTracking(index+1);
            comb[index] = -1;
            ++optr[i];
        }
    }
}

int main(void) {
    scanf("%d", &n);
    seq.resize(n);
    memset(comb, -1, sizeof(comb));

    for(int i=0; i<n; ++i) scanf(" %d", &seq[i]);
    for(int i=0; i<4; ++i) scanf(" %d", &optr[i]);

    backTracking(0);

    printf("%d\n%d", maxVal, minVal);
}