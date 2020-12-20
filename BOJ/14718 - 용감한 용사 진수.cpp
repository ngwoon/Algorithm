#include <bits/stdc++.h>
using namespace std;

/*
    14718 - 용감한 용사 진수

    적어도 k마리 이상의 몬스터를 잡기 위한 최소 스탯을 구하는 문제

    제일 직관적인 방법은, for문 3개로 힘, 민첩, 지능에 대해 인덱싱하고 가장 안쪽 for문으로 해당 스텟보다 모두 작거나 같은 몬스터를 체크한다.
    체크된 몬스터가 k보다 크거나 같으면, 답이 될 수 있는 가능성이 있으므로 ans에 갱신한다.

    시간복잡도를 줄이기 위해 등장하는 스탯 중 중복되는 부분을 제거하고 실행하는 방법도 있다.
    아래 코드는 중복 제거한 풀이

    백준 코드를 보니 이분 탐색을 통해 풀어놓은 코드가 있었는데 확실히 시간이 많이 단축됨을 알 수 있었다.
*/

int input[100][3];
vector<int> stat[3];
int N, K;

int main(void) {
    scanf("%d %d", &N, &K);

    for(int i=0; i<3; ++i) stat[i].resize(N);
    
    for(int i=0; i<N; ++i) {
        scanf(" %d %d %d", &input[i][0], &input[i][1], &input[i][2]);
        stat[0][i] = input[i][0];
        stat[1][i] = input[i][1];
        stat[2][i] = input[i][2];
    }

    for(int i=0; i<3; ++i) {
        sort(stat[i].begin(), stat[i].end());
        stat[i].erase(unique(stat[i].begin(), stat[i].end()), stat[i].end());
    }

    // printf("================\n");
    // for(int i=0; i<3; ++i) {
    //     printf("%d : ", i);
    //     for(int j=0; j<stat[i].size(); ++j)
    //         printf("%d ", stat[i][j]);
    //     printf("\n");
    // }
    // printf("================\n");

    int res = 987654321;
    for(int i=0; i<stat[0].size(); ++i) {
        for(int j=0; j<stat[1].size(); ++j) {
            for(int k=0; k<stat[2].size(); ++k) {
                int cnt=0;
                for(int c=0; c<N; ++c) {
                    if(stat[0][i] >= input[c][0] && stat[1][j] >= input[c][1] && stat[2][k] >= input[c][2])
                        ++cnt;
                }

                if(cnt >= K)
                    res = min(res, stat[0][i] + stat[1][j] + stat[2][k]);
            }
        }
    }

    printf("%d", res);
}