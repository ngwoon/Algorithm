#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>

/*
    백준 1060번 - 구간

    문제를 잘못 이해함

    unlucky "구간" 갯수가 적을수록 우선순위가 높아짐
    구간 갯수를 셀 때 유의해야함 -> lucky set이 {1, 5} 일 때, 정수 2보다 정수 3의 우선순위가 더 낮다.
*/

using namespace std;

vector<int> lucky;
int L, N;

int getSubsetCount(int num) {
    return (num*(num+1))/2;
}

int main(void) {
    scanf("%d", &L);

    lucky.resize(L);
    for(int i=0; i<L; ++i)
        scanf(" %d", &lucky[i]);

    scanf(" %d", &N);

    sort(lucky.begin(), lucky.end());

    int cnt=N;

    for(int i=0; i<L; ++i) {
        if(cnt-- == 0) exit(0);
        printf("%d ", lucky[i]);
    }

    lucky.insert(lucky.begin(), 0);

    vector<tuple<int, int, int>> bounds;
    for(int i=0; i<L; ++i) {
        int start = lucky[i]+1;
        int end = lucky[i+1];

        if(end-start == 0) continue;

        bounds.push_back({end-start, start, end});
    }

    sort(bounds.begin(), bounds.end());

    for(int i=0; i<bounds.size(); ++i) {
        for(int j=get<1>(bounds[i]); j<get<2>(bounds[i]); ++j) {
            if(cnt-- == 0) exit(0);
            printf("%d ", j);
        }
    }

    if(cnt > 0) {
        int num = lucky[L]+1;
        while(cnt--) printf("%d ", num++);
    }
}