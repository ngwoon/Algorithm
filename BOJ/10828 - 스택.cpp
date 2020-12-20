#include <bits/stdc++.h>
using namespace std;

stack<int> stk;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    while(n--) {
        string order;
        cin >> order;

        if(order == "push") {
            int num;
            cin >> num; cin.ignore();
            stk.push(num);
        } else {
            if(order == "pop") {
                if(stk.empty()) cout << "-1" << "\n";
                else {
                    cout << stk.top() << "\n";
                    stk.pop();
                }
            } 
            else if(order == "size")
                cout << stk.size() << "\n";
            else if(order == "empty")
                cout << stk.empty() << "\n";
            else {
                cout << (stk.empty() ? -1 : stk.top()) << "\n";
            }
        }
    }
}