#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str;
    int cnt=0;
    while(cin >> str) {
        ++cnt;
        map<string, int>::iterator iter = mp.find(str);
        if(iter == mp.end()) mp.insert({str, 1});
        else ++iter->second;
    }

    double sum=0;
    for(map<string,int>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
        sum += pow((iter->second/(double)cnt),2);
    }

    cout << 1 - sum;
}