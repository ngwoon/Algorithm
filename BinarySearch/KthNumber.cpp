#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    int low=1;
    int high=K; // K번째 수는 K보다 클 수 없다. 항상 K보다 작거나 같다.
    int mid;
    long long answer;
    while(low <= high) {
        mid = (low + high) / 2;
        long long cnt = 0;
        for(int i=1; i<N + 1; i++) cnt += min(N, mid/i);

        if(cnt < K) low = mid + 1;
        else answer = mid, high = mid - 1;
    }

    cout << answer;
}