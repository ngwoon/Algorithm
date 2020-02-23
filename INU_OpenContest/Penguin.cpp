#include <iostream>

using namespace std;

int power[200000];
int ppos;

int main(void) {
    int N;

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> power[i];
    
        if(power[i] == -1)
            ppos = i;
    }

    // 펭귄의 왼쪽에서 가장 낮은 강도의 얼음 찾기
    unsigned int minPow = 1000000000;
    int result = 0;
    for(int i=0; i<ppos; i++) {
        if(minPow > power[i])
            minPow = power[i];
    }

    result += minPow;

    // 펭귄의 오른쪽에서 가장 낮은 강도의 얼음 찾기
    minPow = 1000000000;
    for(int i=ppos + 1; i<N; i++) {
        if(minPow > power[i])
            minPow = power[i];
    }

    result += minPow;

    cout << result;

    return 0;
}