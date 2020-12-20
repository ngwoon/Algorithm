#include <bits/stdc++.h>
using namespace std;

int N;
string str;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str >> N;

    for(int i=0; i<N; ++i) {
        int a, b;
        cin >> a >> b;

        char temp = str[a];
        str[a] = str[b];
        str[b] = temp;
    }
    cout << str;
}