#include <bits/stdc++.h>
using namespace std;

int heap[100001];
int lastIndex;

void swap(int parent, int child) {
    heap[parent] ^= heap[child];
    heap[child] ^= heap[parent];
    heap[parent] ^= heap[child];
}

int main(void) {
    int n;
    scanf("%d", &n);

    string result;
    for(int i=0; i<n; ++i) {
        int num;
        scanf(" %d", &num);

        if(num == 0) {
            // printf("%d\n", heap[1]);
            result.append(to_string(heap[1]) + "\n");
            heap[1] = heap[lastIndex];
            if(lastIndex >= 1)
                heap[lastIndex--] = 0;

            if(lastIndex > 1) {
                int parent = 1;
                int child = parent << 1;
                if(child + 1 <= lastIndex) {
                    if(abs(heap[child]) == abs(heap[child + 1]))
                        child = heap[child] < heap[child + 1] ? child : child + 1;
                    else
                        child = abs(heap[child]) < abs(heap[child + 1]) ? child : child + 1;
                }

                while(child <= lastIndex && abs(heap[parent]) >= abs(heap[child])) {
                    if(abs(heap[parent]) == abs(heap[child]) && heap[parent] < heap[child])
                        break;
                    swap(parent, child);
                    parent = child;
                    child = parent << 1;
                    if(child + 1 <= lastIndex) {
                        if(abs(heap[child]) == abs(heap[child + 1]))
                            child = heap[child] < heap[child + 1] ? child : child + 1;
                        else
                            child = abs(heap[child]) < abs(heap[child + 1]) ? child : child + 1;
                    }
                }
            }
        } else {
            heap[++lastIndex] = num;

            int child = lastIndex;
            int parent = child >> 1;
            while(parent >= 1 && abs(heap[parent]) >= abs(heap[child])) {
                if(abs(heap[parent]) == abs(heap[child]) && heap[parent] < heap[child])
                    break;
                swap(parent, child);
                child = parent;
                parent = child >> 1;
            }
        }
    }

    printf("%s", result.c_str());
}