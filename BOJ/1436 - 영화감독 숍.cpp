#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    string num("666");
    int cnt=0;
    while(1) {
        bool isDevil=false;
        for(int i=0; i<num.size()-2; ++i) {
            if(num[i] == '6' && num[i] == num[i+1] && num[i+1] == num[i+2]) { isDevil = true; break; }
        }
        if(isDevil) ++cnt;
        if(cnt == n) { cout << num; exit(0); }

        int temp = stoi(num) + 1;
        num = to_string(temp);
    }
}
