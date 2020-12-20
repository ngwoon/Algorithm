#include <bits/stdc++.h>
using namespace std;

queue<int> que;

int main(void) {
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; ++i)
        que.push(i);

    while(que.size() > 1) {
        que.pop();
        que.push(que.front());
        que.pop();
    }
    printf("%d", que.front());
}