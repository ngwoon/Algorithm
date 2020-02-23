#include <bits/stdc++.h>

using namespace std;

int N, H;

bool desc(int a, int b) {
    return a > b;
}

// up : 0 , down : 1
int updown[2][100000];
int len = N / 2;

int info[2][500000];

int main(void) {
    cin >> N >> H;

    for(int i=0; i<N; i++)
        cin >> updown[i%2][i/2];

    sort(updown[0], updown[0] + len, desc);
    sort(updown[1], updown[1] + len, desc);

    for(int i=0; i<2; i++) {
        for(int j=1; j<H; j++) {
            int height = (i % 2 ? H - j : j);
        }
    }
}