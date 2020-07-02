#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int i1 = stoi(s1);
    int i2 = stoi(s2);
    cout << (i1 > i2 ? i1 : i2);
}