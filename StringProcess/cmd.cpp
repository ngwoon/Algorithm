#include <bits/stdc++.h>

using namespace std;

int N;
string words[50];

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> words[i];

    int len = words[0].length();
    string answer;

    for(int i=0; i<len; i++) {
        char cur = words[0][i];
        int j;
        for(j=1; j<N; j++)
            if(cur != words[j][i]) break;
        
        if(j == N) answer += cur;
        else answer += '?';
    }

    cout << answer;
}