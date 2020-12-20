#include <bits/stdc++.h>
using namespace std;

int dx[2] = {-1,1};

queue<tuple<int, int, int>> que;
vector<pair<int, int>> field;
int N, A, B;

int main(void) {
    scanf("%d %d %d", &N, &A, &B);
    field.resize(N+1, {-1,-1});

    que.push({0, A, true});
    que.push({0, B, false});
    field[A] = {0,-1};
    field[B] = {-1,0};

    while(!que.empty()) {
        int cnt = get<0>(que.front());
        int pos = get<1>(que.front());
        bool isA = get<2>(que.front());
        que.pop();

        for(int i=0; i<2; ++i) {
            int nextPos = pos + dx[i]*pow(2,cnt);

            if(nextPos < 1 || nextPos > N) continue;

            int ncnt = cnt+1;
            if(!isA) {
                if(field[nextPos].first == ncnt) {
                    printf("%d", ncnt);
                    exit(0);
                }
            }

            if(isA) field[nextPos].first = ncnt;
            else field[nextPos].second = ncnt;
            que.push({ncnt, nextPos, isA});
        }
    }

    printf("-1");
}