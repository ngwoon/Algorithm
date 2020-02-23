#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
    백준 2098번 - Traveling Salesman Problem (TSP)

    각 노드를 한 번씩만 거쳐(시작노드 제외) 모든 노드를 순회하는 방법

    각 노드를 모두 순회해야 하고, 순회가 가능하다고 문제에서 표현했으므로 시작 노드를 0으로 특정해도 상관이 없다.

    0번노드 ~ (최대) 15번노드의 방문 여부를 15비트 비트열로 표현 -> 비트마스킹
    

    처음엔 백트래킹 기법을 사용하여 풀었으나 시간초과에 걸렸다.

    따라서 dp를 이용하여 풀었다. dp의 행은 현재 도시를, 열은 현재 도시에 오기까지 방문했던 기록을 의미한다.
*/

#define IMP 100000000

int weight_matrix[16][16];
int dp[16][2<<15] = {0,};
int N;
int allVisited;

int solve(int currentCity, int visited) {

    int& ret = dp[currentCity][visited];
    
    if(ret != -1) return ret;

    // 기저 : 모든 노드를 방문했다면
    if(visited == allVisited) {
        if(weight_matrix[currentCity][0] != 0) return weight_matrix[currentCity][0];
        else return IMP;
    }

    ret = IMP;
    for(int i=0; i<N; i++) {
        if(weight_matrix[currentCity][i] == 0) continue;
        if(visited & (1<<i)) continue;

        ret = min(ret, solve(i, visited | (1<<i)) + weight_matrix[currentCity][i]);
    }
    return ret;
}

int main(void) {
    scanf("%d", &N);

    allVisited = (1<<N) - 1;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &weight_matrix[i][j]);

    memset(dp, -1, sizeof(dp));
    printf("%d",solve(0,1));
}