#include <bits/stdc++.h>

using namespace std;

int cnt[26];
vector<string> src;
int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    
    string temp;
    while(getline(cin, temp))
        src.push_back(temp);
    
    int len = src.size();
    for(int i=0; i<len; i++) {
        string cur = src[i];

        int clen = cur.length();
        for(int j=0; j<clen; j++) {
            char c = cur[j];
            if(c == ' ' || c == '\n') continue;
            ++cnt[((int)c - 97)];
        }
    }

    int maxVal = 0;
    vector<char> maxAlp;
    for(int i=0; i<26; i++) {
        if(maxVal < cnt[i]) {
            maxVal = cnt[i];
            maxAlp.clear();
            maxAlp.push_back((char)(i + 97));
        } else if(maxVal == cnt[i])
            maxAlp.push_back((char)(i + 97));
    }

    for(int i=0; i<maxAlp.size(); i++)
        cout << maxAlp[i];
}