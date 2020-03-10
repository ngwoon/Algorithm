#include <bits/stdc++.h>
using namespace std;

/*
    1114번 - 통나무 자르기

    가장 긴 나무의 길이를 기준으로 하는 이분탐색 문제

    문제에서 답이 여러개일 경우 처음으로 자른 포인트가 가장 낮은 경우를 출력하라고 했다.
    따라서 통나무 맨 뒤에서부터 잘라내기 시작한다면, 마지막으로 잘린 포인트가 답이 될 수 있다.
    단, 이분탐색을 끝내고 더 자를 수 있는 횟수가 남아 있을 땐, 첫 번째 컷팅 포인트를 출력해야 한다.
*/

vector<int> logs;
int L,K,C;
pair<int, int> ans = { 1000000001, -1 };

int main(void) {
    scanf("%d %d %d", &L, &K, &C);

    logs.resize(K+2);
    logs[0] = 0;
    for(int i=1; i<=K; ++i) scanf(" %d", &logs[i]);
    logs[K+1] = L;

    sort(logs.begin(), logs.end());

    int low=1, high=1000000000;
    while(low <= high) {
        int mid = (low + high)/2;
        int cnt=0;
        int right = L;
        bool poss=true;
        for(int i=K; i>=0; --i) {
            int left = logs[i];
            
            if(right - left <= mid) continue;
            if(logs[i+1] - logs[i] > mid) { poss=false; break; }
            else { ++cnt; right = logs[i+1]; }
        }

        if(!poss || cnt > C) low = mid + 1;
        else {
            if(cnt < C) ans = { mid, logs[1] };
            else ans = { mid, right }; 
            high = mid - 1; 
        }
    }
    printf("%d %d", ans.first, ans.second);
}