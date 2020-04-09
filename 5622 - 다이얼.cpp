#include <bits/stdc++.h>
using namespace std;

int alphaToNum[26] = {
    2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9
};

int main(void) {
    string str;
    cin >> str;

    int sum=0;
    for(int i=0; i<str.size(); ++i)
        sum += alphaToNum[str[i]-'A'];
    
    sum += str.size();
    cout << sum;
}