#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

vector<int> pos;
int answer = 1000000000;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> C;

    int low = 1, high = 1000000000;
    int mid;

    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        pos.push_back(temp);
    }

    sort(pos.begin(), pos.end());

    int len = pos.size();
    while(low <= high) {
        mid = (low + high) / 2;

        int cnt = 1;
        int install = pos[0];
        for(int i=1; i<len; i++) {
            int gap = pos[i] - install;
            if(gap >= mid) {
                ++cnt;
                install = pos[i];
            }
        }

        if(cnt < C)
            high = mid - 1;
        else {
            low = mid + 1;
            answer = mid;
        }
    }

    cout << answer;
}