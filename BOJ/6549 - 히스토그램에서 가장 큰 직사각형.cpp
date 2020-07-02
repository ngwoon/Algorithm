#include <bits/stdc++.h>
using namespace std;

/*
    6549번 - 히스토그램에서 가장 큰 직사각형

    분할 정복 문제. 하나 신경 써야 할 점은 conquer할 때 기준선을 포함한 직사각형이 더 큰 경우를 고려해야 한다.

    계산할 때 int 와 long long 사이의 계산은 오버플로우가 발생할 수 있음을 잊지 말자.

    스택으로도 구현 가능
*/

vector<int> heights;
int N;

long long conquer(int start, int mid, int end, long long left, long long right) {
    int nowlen = end - start + 1;

    long long ansArea = max(right, left);
    int lindex = nowlen/2 + start, rindex = nowlen/2 + start;
    long long minHeight = heights[nowlen/2 + start];
    long long nowArea;
    while(lindex > start && rindex < end) {
        if(heights[lindex-1] >= heights[rindex+1]) {
            if(minHeight > heights[--lindex]) minHeight = heights[lindex];
        }
        else if(heights[lindex-1] < heights[rindex+1]) {
            if(minHeight > heights[++rindex]) minHeight = heights[rindex];
        }

        nowArea = minHeight * (rindex-lindex+1);
        if(ansArea < nowArea) ansArea = nowArea;
    }
    if(lindex == start) {
        while(rindex < end) {
            if(minHeight > heights[++rindex]) minHeight = heights[rindex];
            nowArea = (rindex-lindex+1) * minHeight;
            if(ansArea < nowArea) ansArea = nowArea;
        }
    } else {
        while(lindex > start) {
            if(minHeight > heights[--lindex]) minHeight = heights[lindex];
            nowArea = (rindex-lindex+1) * minHeight;
            if(ansArea < nowArea) ansArea = nowArea;
        }
    }

    return ansArea;
}

long long divide(int start, int end) {
    if(start == end) return heights[start];

    int mid = (start + end)/2;
    long long left = divide(start, mid);
    long long right = divide(mid+1, end);

    return conquer(start, mid, end, left, right);
}

int main(void) {
    while(1) {
        scanf("%d", &N);
        if(N == 0) break;

        heights.resize(N);
        for(int i=0; i<N; ++i) scanf(" %d", &heights[i]);

        printf("%lld\n", divide(0, N-1));
    }
}