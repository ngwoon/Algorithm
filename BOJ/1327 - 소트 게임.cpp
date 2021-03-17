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
    printf("seq : %s, idx : %d\n", seq.c_str(), idx);
    string front = idx-1 <= 0 ? "" : seq.substr(0, idx-1);
    printf("front : %s\n", front.c_str());
    string sub = seq.substr(idx, k);
    printf("sub : %s\n", sub.c_str());
    string back = k+1 > n ? "" : seq.substr(k);
    printf("back : %s\n", back.c_str());
    reverse(sub.begin(), sub.end());
    newSeq.append(front).append(sub).append(back);
    printf("newSeq : %s\n", newSeq.c_str());
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
            if(i + k - 1 <= n) {
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