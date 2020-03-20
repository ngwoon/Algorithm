#include <bits/stdc++.h>
using namespace std;

/*
    1039번 - 교환

    bfs 구현은 크게 어렵지 않았지만 걸러야 할 조건이 많았던 문제.

    우선 100 미만의 10의 배수나 한 자리 수는 연산이 불가하므로 -1을 출력해야한다.

    bfs 알고리즘을 돌릴 때, 7522 같은 숫자의 경우, 십의자리와 일의자리를 k번 연속하면 가장 큰 수가 나오지만, 
    방문배열 때문에 k번 수행하지 못할 수 있다. 따라서 i번째 연산을 수행하기 전, 방문배열을 초기화해서 7522 와 같은 경우에도
    정상적으로 연산을 수행할 수 있도록 해야 한다.
*/

#define MAX_SIZE 1000001

int str;
queue<int> que;
bool visited[MAX_SIZE];
int K;
int ans = -1;
int lastIndex;

void bfs() {
    que.push(str);
    int cnt=0;

    while(!que.empty()) {
        int qsize = que.size();
        memset(visited, false, MAX_SIZE);
        ++cnt;

        for(int z=0; z<qsize; ++z) {
            int cur = que.front();
            string curStr = to_string(cur);
            que.pop();

            for(int i=0; i<lastIndex; ++i) {
                for(int j=i+1; j<=lastIndex; ++j) {
                    string nstr = curStr;
                    
                    nstr[i] ^= nstr[j];  nstr[j] ^= nstr[i];  nstr[i] ^= nstr[j];

                    if(nstr[0] == '0') continue;

                    int nstrToInt = atoi(nstr.c_str());
                    if(visited[nstrToInt]) continue;
                    
                    visited[nstrToInt] = true;
                    
                    if(cnt == K) {
                        if(ans < nstrToInt) ans = nstrToInt;
                        continue;
                    }

                    que.push(nstrToInt);
                }
            }
        }
        if(cnt == K) break;
    }
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str >> K;

    lastIndex = to_string(str).length()-1;
    bfs();

    cout << ans;
}