#include <bits/stdc++.h>

using namespace std;

int answer = 0;

int N;
string words[100];
int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> words[i];

        if(words[i].length() % 2 == 1)
            continue;
        
        string cur = words[i];
        while(1) {
            int len = cur.length();
            bool erased = false;
            for(int j=0; j<len - 1; j++) {
                if(cur[j] == cur[j + 1]) {
                    cur.erase(cur.begin() + j, cur.begin () + j + 2);
                    erased = true;
                    break;
                }
            }
            if(!erased) {
                if(len == 0) ++answer;
                break;
            }
        }
    }

    cout << answer;
}