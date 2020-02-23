#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
string bomb;

int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str >> bomb;

    stack<char> stk;
    stack<char> tempSave;
    stack<char> answer;

    int slen = str.length();
    int blen = bomb.length();
    for(int i=0; i<slen; i++) {
        if(str[i] == bomb[blen - 1]) {

            tempSave.push(str[i]);

            int j;
            for(j=blen - 2; j>=0; j--) {
                char temp;
                
                if(stk.empty()) {
                    while(!tempSave.empty()) {
                        temp = tempSave.top();
                        tempSave.pop();
                        stk.push(temp);
                    }
                }
                
                temp = stk.top();
                stk.pop();

                if(temp != bomb[j]) {
                    stk.push(temp);
                    while(!tempSave.empty()) {
                        temp = tempSave.top();
                        tempSave.pop();
                        stk.push(temp);
                    }
                    break;
                } else
                    tempSave.push(temp);
            }

            // 폭탄이었을 경우
            if(j == -1) {
                while(!tempSave.empty())
                    tempSave.pop();
            }
        } else
            stk.push(str[i]);
    }

    if(stk.empty())
        cout << "FRULA";
    else {
        while(!stk.empty()) {
            char temp = stk.top();
            stk.pop();
            answer.push(temp);
        }
        while(!answer.empty()) {
            char temp = answer.top();
            cout << temp;
            answer.pop();
        }
    }
}