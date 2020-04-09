#include <bits/stdc++.h>
using namespace std;

vector<int> rest;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    while(cin >> num) {
        int res = num % 42;
        vector<int>::iterator iter = lower_bound(rest.begin(), rest.end(), res);
        if(iter == rest.end() || *iter != res) rest.insert(iter, res);
    }
    cout << rest.size(); 
}