#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string test = "Hello";
    string front = "";
    string sub = test.substr(0, 3);
    string temp;
    temp.append(front).append(sub);
    printf("%s", temp.c_str());
}