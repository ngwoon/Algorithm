#include <bits/stdc++.h>
using namespace std;

/*
    1715 - 카드 정렬하기

    최소 힙을 이용한 문제.

    처음엔 그냥 배열에 입력받아 정렬한 후, 차례로 더해가면 되는 줄 알았지만, 전체 비교 횟수를 최소로 해야 하므로
    현재까지 합친 카드 묶음를 다른 카드 묶음과 비교하여 전체 카드 묶음 중 가장 작은 2개를 계속 더해가야 정답이 나온다.

    따라서 최소 힙을 이용해 두 카드묶음을 골라 비교 횟수를 더하고, 합친 카드 묶음을 다시 최소 힙에 넣어주는 방식으로 풀었다.
*/

multiset<int> myset;
int n;

int main(void) {    
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        int temp;
        scanf(" %d", &temp);
        myset.insert(temp);
    }

    int ans=0;
    while(myset.size() != 1) {
        int v1 = *myset.begin();
        myset.erase(myset.begin());
        int v2 = *myset.begin();
        myset.erase(myset.begin());
        
        ans += v1 + v2;
        myset.insert(v1 + v2);
    }

    printf("%d", ans);
}