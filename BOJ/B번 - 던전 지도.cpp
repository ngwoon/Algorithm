#include <bits/stdc++.h>
using namespace std;

long long cnt;
int yidx[200000];
char blocks[26][200001];
int n,m,k;
queue<pair<int, int>> que;


int main(void) {
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<k; ++i)
        scanf(" %s", blocks[i]);
    
    for(int i=0; i<n; ++i) {
        char c;
        scanf(" %c", &c);
        yidx[i] = c-'A';
    }

    que.push({n-1, m-1});
    while(!que.empty()) {
        ++cnt;
        int idx = que.front().first;
        int x = que.front().second;
        que.pop();
        
        if(idx > 0 && blocks[yidx[idx-1]][x] == 'U')
            que.push({idx-1, x});
        if(x > 0 && blocks[yidx[idx]][x-1] == 'R')
            que.push({idx, x-1});
    }
    printf("%lld", cnt);
}