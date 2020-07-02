#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    int cnt=0;
    for(int i=1; i<=n; ++i) {
        string num = to_string(i);
        int gap = num[1] - num[0];

        bool isOneNum=true;
        for(int j=1; j<num.size()-1; ++j) {
            if(num[j+1] - num[j] != gap) { isOneNum = false; break; }
        }
        if(isOneNum) ++cnt;
    }
    cout << cnt;
}