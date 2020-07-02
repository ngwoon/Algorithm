#include <bits/stdc++.h>
using namespace std;

stack<int> nums;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    cin >> line;

    for(int i=0; i<line.size(); ++i) {
        if(line[i] >= '0' && line[i] <= '9') { nums.push(line[i]-'0'); continue; }

        int op1 = nums.top(); nums.pop();
        int op2 = nums.top(); nums.pop();

        char opt = line[i];

        int res;
        switch(opt) {
            case '+' : res = op1 + op2; break;
            case '-' : res = op2 - op1; break;
            case '*' : res = op1 * op2; break;
            case '/' : res = op2 / op1; break;
        }
        nums.push(res);
    }

    cout << nums.top();
}