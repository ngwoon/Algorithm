#include <bits/stdc++.h>


/*
    1927 - 최소 힙
    
    배열을 이용한 최소 힙 구현 방법을 연습해볼 수 있는 문제.

    heap에서의 삽입
    배열의 가장 마지막 인덱스에 추가. 그곳에서 부모노드와 계속 비교하면서 리팩토링

    heap에서의 삭제
    최상단 부모 삭제. 가장 마지막 인덱스를 최상단 부모로 옮기고, 자식 노드들과 비교하여 리팩토링.
    자식 노드들과 비교할 때, 만약 두 자식 모두 교체 조건을 만족하면 두 노드 중 작은 값과 부모를 교체한다.
*/

int heap[100001];
int lastIndex;

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        int num;
        scanf(" %d", &num);

        if(num == 0) {
            printf("%d\n", heap[1]);
            if(lastIndex >= 1) {
                heap[1] = heap[lastIndex];
                heap[lastIndex--] = 0;

                int parentIndex = 1;
                int childIndex = parentIndex << 1;
                if(childIndex + 1 <= lastIndex)
                    childIndex = heap[childIndex] < heap[childIndex + 1] ? childIndex : childIndex + 1;

                while(childIndex <= lastIndex && heap[parentIndex] > heap[childIndex]) {
                    heap[parentIndex] ^= heap[childIndex];
                    heap[childIndex] ^= heap[parentIndex];
                    heap[parentIndex] ^= heap[childIndex];

                    parentIndex = childIndex;
                    childIndex = parentIndex << 1;
                    if(childIndex + 1 <= lastIndex)
                        childIndex = heap[childIndex] < heap[childIndex + 1] ? childIndex : childIndex + 1;
                }
            }
        } else {
            heap[++lastIndex] = num;
            if(lastIndex != 1) {
                int childIndex = lastIndex;
                while(childIndex > 1) {
                    int parentIndex = childIndex / 2;
                    if(heap[childIndex] < heap[parentIndex]) {
                        heap[childIndex] ^= heap[parentIndex];
                        heap[parentIndex] ^= heap[childIndex];
                        heap[childIndex] ^= heap[parentIndex];
                        childIndex = parentIndex;
                    } else
                        break;
                }
            }
        }
    }
}