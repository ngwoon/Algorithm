#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main(void) {
    string str;
    cin >> str;
    for(int i=0; i<str.size(); ++i)
        ++alpha[toupper(str[i])-'A'];

    int maxCnt=0;
    char maxAlpha='0';
    for(int i=0; i<26; ++i) {
        if(maxCnt < alpha[i]) { maxCnt = alpha[i]; maxAlpha = i+'A'; }
    }
    for(int i=0; i<26; ++i) {
        if(maxCnt == alpha[i] && maxAlpha != (char)(i+'A')) {
            cout << "?"; exit(0);
        }
    }
    cout << maxAlpha;
}