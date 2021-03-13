#include <bits/stdc++.h>
using namespace std;

stack<char> stk;

int main(void) {
    char input[31];
    scanf("%s", input);
    string brackets = input;

    bool isWrong = false;
    int weight = 1;
    int result = 0;
    for(int i=0; i<brackets.length(); ++i) {
        char cur = brackets[i];
        if(cur == '(' || cur == '[') {
            weight *= cur == '(' ? 2 : 3;
            stk.push(cur);
        } else {
            if(stk.empty()) {
                isWrong = true;
                break;
            }
            char before = stk.top();
            stk.pop();
            if((cur == ')' && before == '(') || (cur == ']' && before == '[')) {
                if(brackets[i-1] == '(' || brackets[i-1] == '[')
                    result += weight;
                weight /= cur == ')' ? 2 : 3;
            } else {
                isWrong = true;
                break;
            }
        }
    }

    if(isWrong || !stk.empty())
        printf("0");
    else
        printf("%d", result);
}