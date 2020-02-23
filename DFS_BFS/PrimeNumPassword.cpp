#include <bits/stdc++.h>

// VISITED : 방문
// POSS    : 소수이지만 방문x
// IMP     : 소수가 아님
enum {VISITED, POSS, IMP};

using namespace std;

int T;
queue<pair<int, int>> que;
bool isPrime[10001]; // 1~10000 사이 소수 표시
bool visited[10001]; // bfs시 방문체크

int bfs(int start ,int end) {

    visited[start] = true;
    que.push({start, 0});

    while(!que.empty()) {
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if(cur == end) {
            while(!que.empty())
                que.pop();
            return cnt;
        }

        for(int i=3; i>=0; i--) {
            string scur = to_string(cur);
            for(int j=0; j<10; j++) {
                string nc = scur;
                nc[i] = (char)(48 + j);
                if(nc == scur)
                    continue;
                
                int inc = atoi(nc.c_str());
                if(inc < 1000 || !isPrime[inc] || visited[inc])
                    continue;
                
                visited[inc] = true;
                que.push({inc, cnt + 1});
            }
        }
    }

    return 0;
}

void erasto() {
    for(int i=2; i<=100; i++) {
        if(isPrime[i]) {
            int temp = 10000/i;
            for(int j=2; j<=temp; j++)
                isPrime[i*j] = false;
        }
    }
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    memset(isPrime, true, 10001);
    erasto();

    int answer;
    for(int i=0; i<T; i++) {
        pair<int, int> pw;
        cin >> pw.first >> pw.second;

        if(pw.first == pw.second)
            answer = 0;
        else
            answer = bfs(pw.first, pw.second);

        cout << answer << endl;

        memset(visited, false, 10001);
    }
}