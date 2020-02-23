#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int dx[2] = {-1, 1};

int N, A, B;
int map[500001];

// true : A 정보, false : B 정보
// 마지막 int 자료형 : cnt
queue<pair<pair<int, bool>, int>> que;

void bfs() {
    que.push({{A, true}, 0});
    que.push({{B, false}, 0});

    while(!que.empty()) {
        int pos = que.front().first.first;
        bool isA = que.front().first.second;
        int cnt = que.front().second;
        que.pop();

        int mvlen = pow(2, cnt);

        if(mvlen >= N) {
            cout << -1;
            return;
        }

        cout << "mvlen : " << mvlen << endl;

        if(isA) {

            map[pos] = cnt;

            for(int i=0; i<2; i++) {
                int nx = dx[i] * mvlen;

                if(nx < 1 || nx > N)
                    continue;
                
                que.push({{nx, true}, cnt + 1});
            }
        } else {
            // A,B가 만났을 때
            if(map[pos] == cnt) {
                cout << cnt + 1;
                break;
            }

            for(int i=0; i<2; i++) {
                int nx = dx[i] * mvlen;

                if(nx < 1 || nx > N)
                    continue;
                
                que.push({{nx, false}, cnt + 1});
            }
        }
    }
}

int main(void) {
    cin >> N >> A >> B;

    for(int i=1; i<N + 1; i++)
        map[i] = -1;

    bfs();
} 