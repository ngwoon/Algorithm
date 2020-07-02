#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

/*
    16475번 - 수학 미로
    다익스트라 알고리즘에 몇 가지 추가적인 작업이 필요했던 문제.
    우선, 함정 도시에 방문 시에 스위치를 눌러야 하고, 스위치 누른 횟수가 p가 되면 몇 가지 경로가 변경된다.
    즉, 알고리즘이 진행되면서 가능한 맵을 총 2가지이다.

    dst배열을 3차원 배열로 설정한다. 첫 번째 인자는 맵의 상태, 두 번째 인자는 스위치 누른 횟수, 세 번째 인자는 현재 도시 번호이다.
    dst배열을 위와 같이 설정함으로써 정확히 동일한 상태로 이미 방문했던 도시로 가는 경우의 수만 없애고, 나머지 경우의 수는 허용한다.

    다른 사람의 풀이 안보고, 한 번에 맞춘 문제라 뿌듯하다. 경로 탐색 문제는 서서히 익숙해져 가고 있는 듯 하다.
*/

typedef struct info {
    int cur, dist, p, stat;
}INFO;

struct cmp {
    bool operator()(const INFO& a, const INFO& b) {
        return a.dist > b.dist;
    }
};

priority_queue<INFO, vector<INFO>, cmp> que;
vector<vector<pair<int, int>>> adj[2];
bool isTrap[10001];
int dst[2][11][10001];
int n,m,k,l,p;
int start, dest;

void bfs() {
    que.push({start,0,0,0});
    dst[0][0][start] = 0;

    while(!que.empty()) {
        int cur = que.top().cur;
        int dist = que.top().dist;
        int curp = que.top().p;
        int stat = que.top().stat;
        que.pop();

        if(dist > dst[stat][curp][cur]) continue;

        for(int i=0; i<adj[stat][cur].size(); ++i) {
            int nc = adj[stat][cur][i].second;
            int ndist = dist + adj[stat][cur][i].first;
            int np = curp, nstat = stat;
            
            if(isTrap[nc]) { 
                ++np;
                if(np == p) { np = 0; nstat ^= 1; }
            }

            if(ndist >= dst[nstat][np][nc]) continue;

            dst[nstat][np][nc] = ndist;
            que.push({nc, ndist, np, nstat});
        }
    }
}

int main(void) {
    scanf("%d %d %d %d %d", &n, &m, &k, &l, &p);

    for(int i=0; i<k; ++i) {
        int temp;
        scanf(" %d", &temp);
        isTrap[temp] = true;
    }

    adj[0].resize(n+1);
    adj[1].resize(n+1);
    for(int i=0; i<m-l; ++i) {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);
        adj[0][v1].push_back({w,v2});
        adj[1][v1].push_back({w,v2});
    }

    for(int i=0; i<l; ++i) {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);
        adj[0][v1].push_back({w,v2});
        adj[1][v2].push_back({w,v1});
    }

    scanf(" %d %d", &start, &dest);

    for(int i=0; i<11; ++i) {
        for(int j=0; j<2; ++j) fill(dst[j][i], dst[j][i] + n + 1, INF);
    }
    bfs();
    
    int ans=INF;
    for(int i=0; i<=10; ++i) {
        for(int j=0; j<2; ++j) {
            if(dst[j][i][dest] < ans) ans = dst[j][i][dest];
        }
    }

    printf("%d", ans == INF ? -1 : ans);
}