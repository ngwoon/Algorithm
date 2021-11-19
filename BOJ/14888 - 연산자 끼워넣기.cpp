// #include <bits/stdc++.h>
// using namespace std;

// /*
//     14888 - 연산자 끼워넣기

//     브루트 포스로 푼 문제.
// */

// vector<int> seq;
// int n;
// int optr[4];
// int comb[10];
// int minVal = INT_maxVal, maxValVal = -INT_maxVal;

// void backTracking(int index) {
//     if(index == n-1) {
//         int calc = seq[0];
//         for(int i=0; i<n; ++i) {
//             switch(comb[i]) {
//                 case 0 : calc += seq[i+1]; break;
//                 case 1 : calc -= seq[i+1]; break;
//                 case 2 : calc *= seq[i+1]; break;
//                 case 3 : calc /= seq[i+1]; break;
//             }
//         }
//         if(minVal > calc) minVal = calc;
//         if(maxValVal < calc) maxValVal = calc;
//         return;
//     }

//     for(int i=0; i<4; ++i) {
//         if(optr[i] > 0) {
//             comb[index] = i;
//             --optr[i];
//             backTracking(index+1);
//             comb[index] = -1;
//             ++optr[i];
//         }
//     }
// }

// int main(void) {
//     scanf("%d", &n);
//     seq.resize(n);
//     memset(comb, -1, sizeof(comb));

//     for(int i=0; i<n; ++i) scanf(" %d", &seq[i]);
//     for(int i=0; i<4; ++i) scanf(" %d", &optr[i]);

//     backTracking(0);

//     printf("%d\n%d", maxValVal, minVal);
// }


#include <bits/stdc++.h>
using namespace std;

vector<int> seq;
int op[4];
int n;
int maxVal=-INT_MAX, minVal=INT_MAX;

void operate(int idx, int acc) {
    if(idx == n) {
        maxVal = maxVal < acc ? acc : maxVal;
        minVal = minVal > acc ? acc : minVal;
        return;
    }

    for(int i=0; i<4; ++i) {
        if(op[i] != 0) {
            int nacc = acc;
            switch(i) {
                case 0: nacc += seq[idx]; break;
                case 1: nacc -= seq[idx]; break;
                case 2: nacc *= seq[idx]; break;
                case 3: nacc /= seq[idx]; break;
            }
            --op[i];
            operate(idx+1, nacc);
            ++op[i];
        }
    }
}

int main(void) {
    scanf("%d", &n);

    seq.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d", &seq[i]);
    
    for(int i=0; i<4; ++i)
        scanf("%d", &op[i]);

    operate(1, seq[0]);
    printf("%d\n%d", maxVal, minVal);
}