#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

//8곳 이동 가능. 12시 부터 시계방향으로 0~7인덱스 
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

//체스판 한 변의 길이
int N;
pair<int, int> start;
pair<int, int> dst;
vector<int> answer;

//first : 좌표, second : 이동 횟수
queue<pair<pair<int, int>, int>> que;
bool visited[300][300];

void reset() {
    for(int i=0; i<N; i++)
        memset(visited[i], false, N);
}

void bfs() {
    que.push({start, 0});

    while(!que.empty()) {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int cnt = que.front().second;

        que.pop();

        if(y == dst.first && x == dst.second) {
            answer.push_back(cnt);
            break;
        }

        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if(visited[ny][nx])
                continue;

            visited[ny][nx] = true;

            que.push({{ny, nx}, cnt + 1});
        }
    }

    while(!que.empty())
        que.pop();
}

int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;

    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> N;

        cin >> start.first >> start.second;
        cin >> dst.first >> dst.second;

        bfs();

        reset();
    }

    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << endl;
}