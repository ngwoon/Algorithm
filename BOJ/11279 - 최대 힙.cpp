#include <bits/stdc++.h>
using namespace std;

/*
    11279번 - 최대 힙.
    
    STL을 사용하지 않고 직접 구현해 보았다.

    Heap 자료구조는 배열로 구성되어 있으며, 구현의 편의를 위해 인덱스는 1 부터 시작된다.
    완전 이진 트리 인 만큼, 자식과 부모의 인덱스를 찾기 쉽다.
    노드 삽입, 삭제 두 가지 작업이 존재한다.

    노드 삽입의 경우, lastLeaf 위치에 삽입하고, 부모를 따라 올라가며 부모의 값이 자식보다 작을 경우 갱신해준다.
    노드 삭제의 경우, 루트 노드를 삭제하고 lastLeaf 위치의 노드를 루트에 올려놓은 뒤, 자식노드 중 자신보다 값이 큰 노드가 존재하면 해당 노드로 내려가면서 갱신한다.

    노드 삭제 후 갱신할 때, 탐색 범위를 lastLeaf/2 인덱스까지만 탐색해야 런타임 에러를 피할 수 있다.
*/

int maxHeap[100002];
int lastLeaf;
string ans;

int main(void) {
    int n;
    scanf("%d", &n);
    for(int z=0; z<n; ++z) {
        int num;
        scanf(" %d", &num);

        if(num == 0) {
            if(lastLeaf == 0) {
                ans += "0\n";
            }
            else {
                ans += to_string(maxHeap[1]) + "\n";
                
                maxHeap[1] = maxHeap[lastLeaf];
                maxHeap[lastLeaf] = 0;
                --lastLeaf;

                int index=1;
                while(index <= lastLeaf/2) {
                    int left = index*2;
                    int right = index*2+1;

                    int chngIndex = maxHeap[left] >= maxHeap[right] ? left : right;

                    if(maxHeap[index] >= maxHeap[chngIndex]) break;
                    
                    maxHeap[index] ^= maxHeap[chngIndex];
                    maxHeap[chngIndex] ^= maxHeap[index];
                    maxHeap[index] ^= maxHeap[chngIndex];
                    index = chngIndex;
                }
            }
        } else {
            maxHeap[++lastLeaf] = num;
            int index = lastLeaf;
            int parent = index/2;
            while(parent != 0) {
                if(maxHeap[parent] < maxHeap[index]) {
                    maxHeap[index] ^= maxHeap[parent];
                    maxHeap[parent] ^= maxHeap[index];
                    maxHeap[index] ^= maxHeap[parent];
                    index = parent;
                    parent = index/2;
                }
                else break;
            }
        }
    }

    printf("%s", ans.c_str());
}