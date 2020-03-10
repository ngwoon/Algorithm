#include <bits/stdc++.h>

#define MAX 1000000

/*
    17103번 - 골드바흐 파티션

    전형적인 에라스토테네스 문제
    시간을 조금 더 줄이고 싶다면 소수 구할 때 visited 배열을 통해 한 번 체크한 곳을 다시 체크하지 않는 방향으로
    구현 가능하다.
*/

using namespace std;

vector<bool> isPrime;
int T;

void getErasto() {
    isPrime.resize(MAX+1, true);
    for(int i=2; i<=1000; ++i) {
        int last=MAX/i;
        for(int j=2; j<=last; ++j)
            isPrime[i*j]=false;
    }
}

int getGoldBach(int num) {
    int firstNumLimit = num/2;
    int cnt=0;
    for(int i=2; i<=firstNumLimit; ++i) {
        if(isPrime[i] && isPrime[num-i]) ++cnt;
    }
    return cnt;
}
 
int main(void) {
    cin.sync_with_stdio(true);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    getErasto();
    for(int i=0; i<T; ++i) {
        int N;
        cin >> N;
        cout << getGoldBach(N) << endl;
    }
}