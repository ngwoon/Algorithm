#include <iostream>

using namespace std;

long long N, M;

long long tall[1000001];
long long tree;
long long fellings = 0;
int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    long long high = 0, low = 0;
    long long mid;
    for(int i=1; i<N + 1; i++) {
        cin >> tall[i];
        if(tall[i] > high)
            high = tall[i];
    }

    while(high >= low) {
        mid = (high + low) / 2;

        tree = 0;

        for(int i=1; i<N + 1; i++) {
            if(mid < tall[i])
                tree += (tall[i] - mid);
        }
        
        if(tree >= M) {
            low = mid + 1;
            if(fellings < mid)
                fellings = mid;
        }
        else if(tree < M)
            high = mid - 1;
    }

    cout << fellings;
}