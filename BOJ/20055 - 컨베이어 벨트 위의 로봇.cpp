#include <bits/stdc++.h>
using namespace std;

vector<int> conveyor;
vector<bool> visited;
int s,e;
int broken, step;
int n, k;

int main(void) {
    scanf("%d %d", &n, &k);

    conveyor.resize(2*n);
    for(int i=0; i<2*n; ++i)
        scanf("%d", &conveyor[i]);

    visited.resize(2*n);
    s = 0; e = n-1;
    while(broken < k) {
        ++step;
        
        // 컨베이어 움직이기 전 내릴 위치에 로봇 있으면 내리기
        if(visited[e])
            visited[e] = false;

        // 컨베이어 움직임
        s = (s + 2*n - 1) % (2*n);
        e = (e + 2*n - 1) % (2*n);

        int te = e, ts = s;
        while(te != ts) {
            if(visited[te]) {
                if(te == e)
                    visited[te] = false;
                else {
                    int ne = (te + 1) % (2*n);
                    if(!visited[ne] && conveyor[ne] > 0) {
                        visited[te] = false;
                        visited[ne] = true;
                        conveyor[ne] -= 1;
                        if(conveyor[ne] == 0)
                            ++broken;
                    }
                }
            }
            te = (te + 2*n - 1) % (2*n);
        }

        // 올라가는 위치에 로봇 놓기
        if(!visited[s] && conveyor[s] > 0) {
            visited[s] = true;
            conveyor[s] -= 1;
            if(conveyor[s] == 0)
                ++broken;
        }
    }
    printf("%d", step);
}