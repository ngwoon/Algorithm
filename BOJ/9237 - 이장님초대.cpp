#include <bits/stdc++.h>
using namespace std;

/*
    백준 9237번 - 이장님 초대

    백준 알고리즘 분류가 "트리" 라고 적혀 있지만, 아니었던 문제
    그냥 모든 묘목 배열을 한 번씩 비교하면서 가장 시간이 오래 걸리는 묘목을 찾아내면 된다.

    처음엔 2일부터 심을 묘목을 고른다고 생각했으나, 문제를 풀어보니 1일부터 바로 심을 묘목을 골라 심는것이 맞는 듯 하다.
*/

vector<int> seedlings;
int N;
int ans=0;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    seedlings.resize(N);
    for(int i=0; i<N; ++i) cin >> seedlings[i];

    sort(seedlings.begin(), seedlings.end(), greater<>());

    for(int i=0; i<N; ++i) {
        if(i+seedlings[i]+2 > ans) ans = i+seedlings[i]+2;
    }

    cout << ans;
}