#include <iostream>
#include <stack>
#include <string>
using namespace std;

string openParenthese = "[{(";
string closeParenthese = "]})";

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    string ans;
    while(c--) {
        string line;
        cin >> line;

        stack<char> openc;

        bool isImp = false;
        for(int i=0; i<line.size(); ++i) {
            char cur = line[i];
            if(openParenthese.find(cur) != string::npos)
                openc.push(cur);
            else {
                if(!openc.empty() && openParenthese.find(openc.top()) == closeParenthese.find(cur))
                    openc.pop();
                else
                    isImp = true;
            }
        }
        if(!isImp) {
            if(openc.empty())
                ans.append("YES");
            else
                ans.append("NO");
        } else
            ans.append("NO");
        ans.append("\n");
    }
    cout << ans;
}