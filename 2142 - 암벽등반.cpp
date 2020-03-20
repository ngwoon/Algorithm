#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
    백준 2412 - 암벽 등반

    bfs응용문제
    입력이 많은 관계로, 홈을 오름차순으로 정렬 후 x좌표와 y좌표 차이가 모두 2를 넘어가면 홈 탐색을 중단하는 식으로
    진행해야 시간초과를 피할 수 있다.

    이 코드에선 lower_bound를 사용하여 logN 타임안에 인덱스를 찾는 방식으로 진행하였으나, queue에 인덱스를 계속 저장하면
    위 시간마저 줄일 수 있을 것으로 예상된다.
    이에 두 가지 코드로 백준에 채점해 보았다.

    결과는 4ms 차이로 인덱스를 저장해 나가는 방식이 아주 조금 더 빠르다. O(logN) 타임은 굉장히 빠른 시간복잡도라는 것을 체감할 수 있다.
*/


queue<pair<pair<int, int>, pair<int, int>>> que;
vector<pair<int, int>> points;
vector<bool> visited;
int n,T;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return (a.second < b.second);
    else return (a.first < b.first);
}

int bfs() {
    que.push({{0,0},{0,0}});
    visited[0] = true;

    while(!que.empty()) {
        pair<int, int> cur = que.front().second;
        int y = cur.first;
        int x = cur.second;
        int cnt = que.front().first.first;
        int index = que.front().first.second;
        que.pop();

        if(y == T) return cnt;

        //vector<pair<int, int>>::iterator start = lower_bound(points.begin(), points.end(), cur);
        //if(start == points.end()) continue;

        //int index = start-points.begin();
        for(int i=index; i<n+1; ++i) {
            int ny = points[i].first;
            int nx = points[i].second;

            if(!visited[i]) {
                if(abs(y - ny) <= 2 && abs(x - nx) <= 2) {
                    visited[i] = true;
                    que.push({{cnt+1,i}, points[i]});
                }
                else if(abs(y - ny) > 2 && abs(x - nx) > 2) break;
            }
        }
        for(int i=index; i>0; --i) {
            int ny = points[i].first;
            int nx = points[i].second;

            if(!visited[i]) {
                if(abs(y - ny) <= 2 && abs(x - nx) <= 2) {
                    visited[i] = true;
                    que.push({{cnt+1,i}, points[i]});
                }
                else if(abs(y - ny) > 2 && abs(x - nx) > 2) break;
            }
        }
    }
    
    return -1;
}

int main(void) {
    scanf("%d %d", &n, &T);

    points.resize(n+1);
    points[0] = {0,0};
    visited.resize(n+1, false);
    for(int i=1; i<n+1; ++i) {
        int x,y;
        scanf(" %d %d", &x, &y);

        points[i] = {y,x};
    }

    sort(points.begin(), points.end(), comp);

    printf("%d",bfs());
}