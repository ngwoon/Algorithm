#include <bits/stdc++.h>
using namespace std;

set<string> visited;
queue<pair<string, int>> que;
int n, k;

bool isAsc(string& seq) {
    for(int i=1; i<=n; ++i) {
        if(seq[i-1]-'0' != i)
            return false;
    }
    return true;
}

string reverseSeq(string seq, int idx) {
    string newSeq;
    string front = idx == 0 ? "" : seq.substr(0, idx);
    string sub = seq.substr(idx, k);
    string back = k+idx-1 == n ? "" : seq.substr(idx+k);
    reverse(sub.begin(), sub.end());
    newSeq.append(front).append(sub).append(back);
    return newSeq;
}

void bfs(string& start) {
    visited.insert(start);
    que.push({start, 0});
    while(!que.empty()) {
        string seq = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if(isAsc(seq)) {
            printf("%d", cnt);
            return;
        }

        for(int i=0; i<n; ++i) {
            if(i + k <= n) {
                string next = reverseSeq(seq, i);
                if(visited.find(next) != visited.end())
                    continue;

                visited.insert(next);
                que.push({next, cnt+1});
            }
        }
    }
    printf("-1");
}

int main(void) {
    scanf("%d %d", &n, &k);
    string seq;
    for(int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        seq.append(to_string(num));
    }
    bfs(seq);
}