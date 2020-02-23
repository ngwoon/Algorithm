#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int arr[4][4000];
int mixArr[2][16000000];
vector<int> increase;

int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++)
        for(int j=0; j<4; j++)
            cin >> arr[j][i];
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            mixArr[0][i*N + j] = arr[0][i] + arr[1][j];
            mixArr[1][i*N + j] = arr[2][i] + arr[3][j];
        }
    }

    int len = N*N;
    sort(mixArr[1], mixArr[1] + len);
    sort(mixArr[0], mixArr[0] + len);

    long long cnt = 0;
    for(int i=0; i<len; i++) {
        if(i != 0 && mixArr[0][i] == mixArr[0][i - 1]) {
            if(i == 1) cnt += increase[i - 1];
            else cnt += (increase[i - 1] - increase[i - 2]);
            increase.push_back(cnt);
            continue;
        }
        int cur = mixArr[0][i];

        int low = 0, high = len - 1;
        int mid;

        while(low <= high) {
            mid = (low + high) / 2;

            int sum = cur + mixArr[1][mid];

            if(sum > 0) high = mid - 1;
            else if(sum < 0) low = mid + 1;
            else {
                ++cnt;
                int tempMid = mid;
                while(mid >= 1 && mixArr[1][mid] == mixArr[1][--mid]) ++cnt;
                mid = tempMid;
                while(mid < len - 1 && mixArr[1][mid] == mixArr[1][++mid]) ++cnt;
                break;
            }
        }

        increase.push_back(cnt);
    }

    cout << cnt;
}