#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<char> alpha[50]; // 입력으로 주어지는 단어에서 서로 다른 알파벳의 종류 각각 저장
vector<char> used;      // 전체 단어에서 쓰인 알파벳의 총 종류
vector<char> learn;     // 백트래킹으로 뽑아낼 알파벳 경우의 수 저장

//anta tica는 무조건 읽을 수 있어야함
//즉, a c i n t 5개의 글자를 배울 수 없으면 어떤 단어도 읽을 수 없음

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    if(K < 5) {
        cout << 0;
        exit(0);
    }

    K -= 5;

    used.push_back('a');
    used.push_back('c');
    used.push_back('i');
    used.push_back('n');
    used.push_back('t');

    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        int len = temp.length();
        for(int j=4; j<len - 4; j++) {
            char c = temp[j];
            int k;
            for(k=0; k<alpha[i].size(); k++) {
                if(alpha[i][k] == c)
                    break;
            }
            if(k == alpha[i].size()) {
                alpha[i].push_back(c);
                for(k=0; k<used.size(); k++) {
                    if(used[k] == c)
                        break;
                }
                if(k == used.size())
                    used.push_back(c);
            }            
        }
    }

    int klen = used.size() - 5;
    if(K >= klen) {
        cout << N;
        exit(0);
    }

    while(1) {
        for(int i=0; i<klen; i++) {
            learn.push_back(used[i + 5]);
        }
    }
}