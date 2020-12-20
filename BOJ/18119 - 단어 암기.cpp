#include <bits/stdc++.h>
using namespace std;

/*
    18119번 - 단어 암기
    시간복잡도 압박이 있는 문제는 비트마스킹을 통한 시간 절약을 생각하자.
    bool 배열을 통한 상태 검사는 굉장히 자주 쓰이는 기법인 듯 하다.
*/

vector<int> words;
int stat;
string ans;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    words.resize(n,0);
    for(int i=0; i<n; ++i) {
        string temp;
        cin >> temp;

        words[i] = 0;
        for(int j=0; j<temp.length(); ++j)
            words[i] |= (1<<(temp[j]-'a'));
   }

    // 쿼리가 주어질 때, 해당 비트의 현재 상태가 보장되어 있으므로 XOR 연산 사용 가능
    stat = (1<<26)-1;
    for(int i=0; i<m; ++i) {
        char c; int num; int cnt=0;
        cin >> num >> c;
        
        stat ^= (1<<(c-'a'));

        for(int j=0; j<n; ++j) {
            if((words[j] & stat) == words[j]) ++cnt;
        }
        ans += to_string(cnt) + "\n";
    }

    cout << ans;
}