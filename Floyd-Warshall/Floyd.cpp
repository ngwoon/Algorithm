#include <stdio.h>
#include <vector>
#define INF 100000001

/*
    플로이드 - 와샬 알고리즘
    백준 11404번 - 플로이드

    일반적인 플로이드는 모든 정점에서 모든 정점으로의 최단 거리와 그 경로를 구한다.
    하지만, 이 문제의 경우 경로를 구할 필요는 없고, 통상적으로 갈 수 없는곳의 거리를 INF로 해둔 것을
    출력할 때 0으로 바꾸어 출력해야 했던 문제

    벡터로 메모이제이션 배열을 만들 때, 초기화 시 j를 0부터 N + 1개 초기화 해 주는 것을 잊지 말자
*/

using namespace std;

vector<vector<int>> table;
int N, B; // 도시의 갯수, 버스의 갯수

int main(void) {
    scanf("%d %d", &N, &B);

    table.resize(N + 1);
    for(int i=1; i<N + 1; i++) {
        for(int j=0; j<N + 1; j++) {
            if(i == j) table[i].push_back(0);
            else table[i].push_back(INF);
        }
    }
    for(int i=0; i<B; i++) {
        int s, e, w;
        scanf(" %d %d %d", &s, &e, &w);
        if(table[s][e] != INF) {
            if(table[s][e] > w) table[s][e] = w;
        }
        else table[s][e] = w;
    }

    for(int i=1; i<N + 1; i++) {
        for(int j=1; j<N + 1; j++) {
            for(int k=1; k<N + 1; k++) {
                if(table[k][j] > table[k][i] + table[i][j]) {
                    table[k][j] = table[k][i] + table[i][j];
                }
            }
        }
    }

    for(int i=1; i<N + 1; i++) {
        for(int j=1; j<N + 1; j++) {
            if(table[i][j] != INF) printf("%d ", table[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
}