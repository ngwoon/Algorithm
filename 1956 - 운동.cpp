#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

/*
    1956번 - 운동
    그래프 내 사이클을 찾는 문제.
    사이클은 dfs를 이용할 수도, 플로이드-와샬을 이용할 수도 있다.
    
    처음엔 dfs를 v번 실행하여 사이클을 찾았지만, TLE가 났다.
    
    그래서 플로이드-와샬을 이용해 모든 노드로부터 모든 노드까지의 최단 거리를 구한 후,
    dst[i][j] + dst[j][i] 중 가장 작은 값을 답으로 삼았다.

    시간복잡도를 계산해보면, dfs를 이용하는 방법도 O(v^3), 플로이드-와샬도 O(v^3) 인데
    왜 dfs만 TLE가 나는지는 잘 모르겠다. 시간복잡도 계산을 다시 해 봐야겠다.
*/

vector<vector<int>> adj;
vector<vector<int>> dst;
int minDst=INF;

int main(void) {
    int v,e;
    scanf("%d %d", &v, &e);
    
    dst.resize(v);
    for(int i=0; i<v; ++i) dst[i].resize(v,INF);
    for(int i=0; i<v; ++i) dst[i][i] = 0;

    for(int i=0; i<e; ++i) {
        int v1,v2,w;
        scanf(" %d %d %d", &v1, &v2, &w);
        dst[v1-1][v2-1] = w;
    }

    for(int i=0; i<v; ++i) {
        for(int j=0; j<v; ++j) {
            for(int k=0; k<v; ++k) {
                if(dst[k][i] == INF || dst[i][j] == INF) continue;
                if(dst[k][j] > dst[k][i] + dst[i][j])
                    dst[k][j] = dst[k][i] + dst[i][j];
            }
        }
    }

    for(int i=0; i<v; ++i) {
        for(int j=0; j<v; ++j) {
            if(i == j) continue;
            if(dst[j][i] == INF) continue;

            if(minDst > dst[i][j] + dst[j][i]) minDst = dst[i][j] + dst[j][i];
        }
    }

    printf("%d", minDst == INF ? -1 : minDst);
}