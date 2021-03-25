#include <bits/stdc++.h>
using namespace std;

string deleteChar(string new_id) {
    string ret = "";
    for(int i=0; i<new_id.length(); ++i) {
        char cur = new_id[i];
        if(isdigit(cur) || (cur >= 97 && cur <= 122) || cur == '-' || cur == '_' || cur == '.')
            ret.push_back(cur);
    }
    return ret;
}

string solution(string new_id) {    
    for(int i=0; i<new_id.length(); ++i) {
        if(new_id[i] >= 65 && new_id[i] <= 90)
            new_id[i] += 32;
    }

    new_id = deleteChar(new_id);

    while(true) {
        int idx = new_id.find("..");
        if(idx != string::npos)
            new_id.replace(idx, 2, ".");
        else
            break;
    }

    if(new_id[0] == '.')
        new_id.erase(new_id.begin());
    if(new_id.back() == '.')
        new_id.pop_back();
    
    if(new_id.empty())
        new_id.push_back('a');
    
    if(new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        if(new_id.back() == '.')
            new_id.pop_back();
    }
    
    if(new_id.length() <= 2) {
        while(new_id.length() != 3)
            new_id.push_back(new_id.back());
    }

    return new_id;
}

int main(void) {
    string str;
    cin >> str;
    solution(str);
}

