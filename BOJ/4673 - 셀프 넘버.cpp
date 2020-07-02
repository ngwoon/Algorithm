#include <bits/stdc++.h>
using namespace std;
bool selfnum[10001];

int main(void) {
    memset(selfnum, true, sizeof(selfnum));
    for(int i=1; i<=10000; ++i) {
        string num = to_string(i);
        int dn=i;
        for(int j=0; j<num.size(); ++j) {
            dn += num[j]-'0';
        }
        if(dn <= 10000)
            selfnum[dn] = false;
    }
    for(int i=1; i<=10000; ++i) {
        if(selfnum[i]) cout << i << "\n";
    }
}