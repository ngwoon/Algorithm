#include <iostream>

using namespace std;

int N, M, K;

int len[100][100];

int check[100] = {0};

int main(void) {
    cin >> N >> M >> K;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) 
            cin >> len[i][j];
    }

    int turn = 0;
    while(1) {
        for(int i=0; i<N; i++) {
            check[i] += len[i][turn];
            if(check[i] >= K) {
                cout << i + 1 << " " << turn + 1;
                exit(0);
            }
        }
        ++turn;
    }
}
