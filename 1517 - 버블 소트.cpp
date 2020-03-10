#include <cstdio>
#include <vector>
using namespace std;

/*
    1517번 - 버블 소트

    버블 소트에서 swap횟수를 구하는 문제
    N이 50만으로 상당히 크다. 즉, O(NlogN) 안에 풀어야 하는 문제
    따라서 병합 정렬에서, 왼쪽 배열보다 오른쪽 배열의 요소가 작을 때 swap되야하는 성질을 이용하여 시간 조건 안에 풀 수 있다.
*/

int N;
long long cnt=0;
vector<int> list;

void merge(int start, int mid, int end) {
    int lindex=start;
    int rindex=mid+1;
    int ansIndex=0;

    vector<int> temp;
    temp.resize(end-start+1);
    for(int i=start; i<=end; ++i) temp[i-start] = list[i];

    while(lindex <= mid && rindex <= end) {
        if(list[lindex] <= list[rindex]) { temp[ansIndex] = list[lindex]; ++lindex; }
        else { cnt += (mid - lindex + 1); temp[ansIndex] = list[rindex];  ++rindex; }
        ++ansIndex;
    }

    // 오른쪽 배열에 요소가 남아있을 때
    if(lindex > mid) {
        while(rindex <= end) { temp[ansIndex] = list[rindex]; ++ansIndex; ++rindex; }
    } else {
        while(lindex <= mid) { temp[ansIndex] = list[lindex]; ++ansIndex; ++lindex; }
    }

    for(int i=start; i<=end; ++i) list[i] = temp[i-start];
}

void solve(int start, int end) {
    if(start >= end) return;
    
    int mid = (start + end)/2;
    solve(start, mid);
    solve(mid+1, end);
    merge(start, mid, end);
}

int main(void) {
    scanf("%d", &N);
    list.resize(N);
    for(int i=0; i<N; ++i) scanf(" %d", &list[i]);

    solve(0, N-1);
    printf("%lld", cnt);
}