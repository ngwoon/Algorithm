#include <bits/stdc++.h>
using namespace std;


/*
    13418번 - 학교 탐방하기

    최소 스패닝 트리 (MST) 를 이용한 문제

    MST개념을 몰랐어서 한참 헤맸다.
    문제에서 내리막으로 내려갔다가 오르막으로 올라오는 건 피로도에 포함시키지 않는다고 했는데, 이것이
    최소 스패닝 트리 문제라는 것을 알려주는 힌트였다.

    크루스칼 알고리즘을 사용했다. 유니온 파인드를 사용한 알고리즘인데, 실질적인 시간복잡도는 정렬하는데 걸리는 시간이다.
    (STL 기준 퀵 소트이므로 O(NlogN))
*/

vector<int> parent;
vector<tuple<int,int,int>> edge;
int mink, maxk;
int N, M;

int Find(int x) {   
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) { x ^= y; y ^= x; x ^= y; }

    if(x != y) { parent[y] = x; return true; }
    else return false;
}

int kruskal() {
    int res=0;
    for(int i=0; i<edge.size(); ++i) {
        if(Union(get<1>(edge[i]), get<2>(edge[i])))
            res += get<0>(edge[i]);
    }

    return res;
}

// 문제에서는 0이 오르막길, 1이 내리막길이지만
// 코딩의 편의를 위해 1을 오르막길, 0을 내리막길로 바꾸어 표현하였다.
int main(void) {
    scanf("%d %d", &N, &M);

    parent.resize(N+1);
    for(int i=0; i<=N; ++i) parent[i] = i;

    for(int i=0; i<M+1; ++i) {
        int v1, v2, w;
        scanf(" %d %d %d", &v1, &v2, &w);

        w ^= 1;
        edge.push_back({w, v1, v2});
    }

    sort(edge.begin(), edge.end());
    int mink = kruskal();

    for(int i=0; i<=N; ++i) parent[i] = i;
    sort(edge.begin(), edge.end(), greater<>());

    int maxk = kruskal();

    printf("%d", maxk*maxk - mink*mink);
}