#include <bits/stdc++.h>

using namespace std;

double X, Y;
int now;
int answer = 0;

int main(void) {
    cin >> X >> Y;

    now = (100*Y)/X;

    int low = 1, high = 1000000000;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        int sum = (100*(Y + mid))/(X + mid);

        if(sum != now) {
            answer = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }

    cout << (answer == 0 ? -1 : answer);
}