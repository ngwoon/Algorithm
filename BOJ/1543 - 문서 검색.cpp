#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);

    int ans = 0;
    int slen = str.length();
    int plen = pattern.length();
    for(int i=0; i<slen; ++i) {
        if(str[i] == pattern[0]) {
            bool isSame = true;
            for(int j=1; j<plen; ++j) {
                if(str[i+j] != pattern[j]) {
                    isSame = false;
                    break;
                }
            }
            if(isSame) {
                ++ans;
                i += plen-1;
            }
        }
    }
    cout << ans;
}