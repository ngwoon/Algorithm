#include <bits/stdc++.h>
using namespace std;

int que[2000000];
int front = -1, rear = -1;
string ans;

bool isEmpty() {
    return front == rear;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        char order[6];
        scanf(" %s", order);

        if(strcmp(order, "push") == 0) {
            scanf("%d", &que[++rear]);
        } else if(strcmp(order, "pop") == 0) {
            printf("%d\n", isEmpty() ? -1 : que[++front]);
        } else if(strcmp(order, "size") == 0) {
            printf("%d\n", rear - front);
        } else if(strcmp(order, "empty") == 0) {
            printf("%d\n", isEmpty() ? 1 : 0);
        } else if(strcmp(order, "front") == 0) {
            printf("%d\n", isEmpty() ? -1 : que[front + 1]);
        } else if(strcmp(order, "back") == 0) {
            printf("%d\n", isEmpty() ? -1 : que[rear]);
        }
    }
}