#include <iostream>

using namespace std;

int K, N;

long long LAN[10001];
long long answer=0;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K >> N;

    long long high = 0, low = 1;
    for(int i=0; i<K; i++) {
        cin >> LAN[i];
        if(LAN[i] > high)
            high = LAN[i];
    }

    long long mid;

    while(low <= high) {
        mid = (low + high) / 2;

        long long cnt = 0;

        for(int i=0; i<K; i++)
            cnt += (LAN[i] / mid);

        if(cnt >= N) {
            answer = (answer < mid ? mid : answer);
            low = mid + 1;
        } else
            high = mid - 1;
    }

    cout << answer;
}