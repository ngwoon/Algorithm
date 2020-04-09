#include <bits/stdc++.h>
using namespace std;

int idx[26];

int main(void) {
    string str;
    cin >> str;

    memset(idx, -1, sizeof(idx));

    for(int i=0; i<str.size(); ++i) {
        if(idx[str[i]-'a'] == -1)
            idx[str[i]-'a'] = i;
    }

    for(int i=0; i<26; ++i)
        cout << idx[i] << " ";
}