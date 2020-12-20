#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);

    string ans;

    cin.ignore();
    for(int z=0; z<t; ++z) {
        string line;
        getline(cin, line);

        int sum=0;
        int seq=0;
        for(int i=0; i<line.size(); ++i) {
            if(line[i] == 'O') {
                ++seq;
                sum += seq;
            }
            else seq=0;
        }

        ans += to_string(sum) + "\n";
    }
    printf("%s", ans.c_str());
}