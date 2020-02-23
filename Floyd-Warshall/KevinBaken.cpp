#include <stdio.h>
#include <vector>
#define INF 9999999
#define NIL -1 
using namespace std;

vector<vector<pair<int, int>>> table;
int N, M;
int main(void) {
    scanf("%d %d", &N, &M);
    table.resize(N + 1);

    for(int i=1; i<N + 1; i++) {
        for(int j=0; j<N + 1; j++) {
            table[i].push_back({INF, NIL});
            if(i == j) { table[i][j].first = 0; table[i][j].second = i; }
        }
    }

    for(int i=0; i<M; i++) {
        int v1, v2;
        scanf(" %d %d", &v1, &v2);
        table[v1][v2].first = 1;
        table[v2][v1].first = 1;
        table[v1][v2].second = v1;
        table[v2][v1].second = v2;
    }

    for(int i=1; i<N + 1; i++) {
        for(int j=1; j<N + 1; j++) {
            for(int k=1; k<N + 1; k++) {
                if(table[k][j].first > table[k][i].first + table[i][j].first) {
                    table[k][j].first = table[k][i].first + table[i][j].first;
                    table[k][j].second = table[i][j].second;
                }
            }
        }
    }

    int minVal = 5001;
    int minPer = -1;
    for(int i=1; i<N + 1; i++) {
        int sum = 0;
        for(int j=1; j<N + 1; j++) {
            int pre = j;
            while(i != table[i][pre].second) {
                pre = table[i][pre].second;
                sum += table[i][j].first;
            }
        }
        if(minVal > sum) {
            minPer = i;
            minVal = sum;
        }
    }

    printf("%d", minPer);
}