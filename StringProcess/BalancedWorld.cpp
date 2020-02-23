#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> open;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1) {
        string input;

        getline(cin, input);

        if(input == ".")
            break;

        int len = input.length();
        for(int i=0; i<len; i++) {
            if(input[i] == '.') {
                if(open.empty())
                    cout << "yes" << endl;
                else
                    goto WRONG;
            }
            else if(input[i] == '[' || input[i] == '(')
                open.push(input[i]);
            else if(input[i] == ']' || input[i] == ')') {
                char couple;
                if(open.empty())
                    goto WRONG;

                couple = open.top();
                open.pop();

                // 짝이 맞지 않는 경우
                if((input[i] == ']' && couple == '(') || (input[i] == ')' && couple == '[')) {
WRONG:
                    while(!open.empty())
                        open.pop();

                    cout << "no" << endl;

                    break;
                }
            }
        }
    }
}