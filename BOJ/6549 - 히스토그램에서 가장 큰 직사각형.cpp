// #include <bits/stdc++.h>
// using namespace std;

// /*
//     6549번 - 히스토그램에서 가장 큰 직사각형

//     분할 정복 문제. 하나 신경 써야 할 점은 conquer할 때 기준선을 포함한 직사각형이 더 큰 경우를 고려해야 한다.

//     계산할 때 int 와 long long 사이의 계산은 오버플로우가 발생할 수 있음을 잊지 말자.

//     스택으로도 구현 가능
// */

// vector<int> heights;
// int N;

// long long conquer(int start, int mid, int end, long long left, long long right) {
//     int nowlen = end - start + 1;

//     long long ansArea = max(right, left);
//     int lindex = nowlen/2 + start, rindex = nowlen/2 + start;
//     long long minHeight = heights[nowlen/2 + start];
//     long long nowArea;
//     while(lindex > start && rindex < end) {
//         if(heights[lindex-1] >= heights[rindex+1]) {
//             if(minHeight > heights[--lindex]) minHeight = heights[lindex];
//         }
//         else if(heights[lindex-1] < heights[rindex+1]) {
//             if(minHeight > heights[++rindex]) minHeight = heights[rindex];
//         }

//         nowArea = minHeight * (rindex-lindex+1);
//         if(ansArea < nowArea) ansArea = nowArea;
//     }
//     if(lindex == start) {
//         while(rindex < end) {
//             if(minHeight > heights[++rindex]) minHeight = heights[rindex];
//             nowArea = (rindex-lindex+1) * minHeight;
//             if(ansArea < nowArea) ansArea = nowArea;
//         }
//     } else {
//         while(lindex > start) {
//             if(minHeight > heights[--lindex]) minHeight = heights[lindex];
//             nowArea = (rindex-lindex+1) * minHeight;
//             if(ansArea < nowArea) ansArea = nowArea;
//         }
//     }

//     return ansArea;
// }

// long long divide(int start, int end) {
//     if(start == end) return heights[start];

//     int mid = (start + end)/2;
//     long long left = divide(start, mid);
//     long long right = divide(mid+1, end);

//     return conquer(start, mid, end, left, right);
// }

// int main(void) {
//     while(1) {
//         scanf("%d", &N);
//         if(N == 0) break;

//         heights.resize(N);
//         for(int i=0; i<N; ++i) scanf(" %d", &heights[i]);

//         printf("%lld\n", divide(0, N-1));
//     }
// }


#include <bits/stdc++.h>
using namespace std;

#define INF 1000000001

vector<int> height;
vector<int> tree;
int n;

int init(int start, int end, int tidx) {
    if(start == end)
        return tree[tidx] = start;

    int mid = (start + end) / 2;
    int li = init(start, mid, tidx*2);
    int ri = init(mid+1, end, tidx*2+1);
    return tree[tidx] = height[li] < height[ri] ? li : ri;
}

int query(int start, int end, int tidx, int left, int right) {
    
    if(end < left || start > right)
        return INF;
    if(start >= left && end <= right)
        return tree[tidx];
    
    int mid = (start + end) / 2;
    int li = query(start, mid, tidx*2, left, right);
    int ri = query(mid+1, end, tidx*2+1, left, right);
    if(li == INF)
        return ri;
    else if(ri == INF)
        return li;
    else
        return height[li] < height[ri] ? li : ri;
}

long long findArea(int start, int end) {
    long long maxArea;
    int minIdx = query(0, n-1, 1, start, end);

    maxArea = height[minIdx] * (long long)(end-start+1);

    if(start < minIdx)
        maxArea = max(maxArea, findArea(start, minIdx-1));
    if(end > minIdx)
        maxArea = max(maxArea, findArea(minIdx+1, end));
    return maxArea;
}

int main(void) {
    while(1) {
        scanf("%d", &n);

        if(n == 0)
            break;

        height.resize(n);
        for(int i=0; i<n; ++i)
            scanf("%d", &height[i]);

        tree.resize(n*4);
        init(0, n-1, 1);
        printf("%lld\n", findArea(0, n-1));
    }
}