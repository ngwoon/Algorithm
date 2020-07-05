#include <bits/stdc++.h>
using namespace std;

/*
    12015 - 가장 긴 증가하는 부분 수열 2

    LIS의 다른 풀이 방법.

    11053번 문제에서 동적 계획법을 사용했다면, 여기서는 lower_bound (이분탐색) 을 사용하여 NlogN 으로 문제를 해결했다.
    
    <풀이>
    입력으로 받은 수열을 앞에서부터 선형 탐색한다.
    탐색 이전에 벡터 하나를 준비하여 굉장히 작은 수를 넣어둔다.
    수열 원소를 순회하면서 각 원소와 벡터의 가장 끝 값을 비교한다.
    벡터값이 더 작으면 현재 수열 원소를 벡터 끝에 추가하고, 수열 원소가 더 작으면 벡터 내에서 해당 원소의 값이 들어갈 위치를 lower_bound로 찾는다.
    그리고 해당 위치의 벡터값을 수열 원소와 교체한다. (추가가 아니다!)

    위 과정을 모든 수열 원소에 대해 진행하면, 주어진 수열에서 가장 긴 증가하는 부분 수열을 구할 수 있다.

    참고로 처음에 넣어둔 굉장히 작은 정수값이 남아있는 상태이므로 이 원소를 제외하여 길이를 구해야 정답이다. 
*/

vector<int> longest;
int seq[1000001];
int n;

int main(void) {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &seq[i]);

    longest.push_back(-1000001);
    for(int i=1; i<=n; ++i) {
        if(longest.back() < seq[i])
            longest.push_back(seq[i]);
        else if(longest.back() > seq[i])
            *lower_bound(longest.begin(), longest.end(), seq[i]) = seq[i];
    }

    printf("%d", longest.size() - 1);
}