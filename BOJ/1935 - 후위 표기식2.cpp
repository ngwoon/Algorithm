#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    int nums[26];
    string exp;
    stack<double> op;

    cin >> n >> exp;
    int len = exp.length();

    for(int i=0; i<n; ++i)
        cin >> nums[i];
    
    for(int i=0; i<len; ++i) {
        char cur = exp[i];
        if(cur == '+' || cur == '-' || cur == '*' || cur == '/') {
            double b = op.top();
            op.pop();
            double a = op.top();
            op.pop();
            double res = 0;
            switch(cur) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            op.push(res);
        } else {
            op.push(nums[cur - 'A']);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << floor(op.top() * 100) / 100;
}