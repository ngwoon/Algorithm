#include <bits/stdc++.h>
using namespace std;

pair<char, char> node[26];
int N;

void postorder(char cur) {
    if(node[cur-'A'].first != '.') postorder(node[cur-'A'].first);
    if(node[cur-'A'].second != '.') postorder(node[cur-'A'].second);
    cout << cur;
}

void inorder(char cur) {
    if(node[cur-'A'].first != '.') inorder(node[cur-'A'].first);
    cout << cur;
    if(node[cur-'A'].second != '.') inorder(node[cur-'A'].second);
}

void preorder(char cur) {
    cout << cur;
    if(node[cur-'A'].first != '.') preorder(node[cur-'A'].first);
    if(node[cur-'A'].second != '.') preorder(node[cur-'A'].second);
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    cin.ignore();
    for(int i=0; i<N; ++i) {
        string info;
        getline(cin, info);

        node[info[0]-65] = {info[2], info[4]};
    }

    preorder('A'); cout << "\n";
    inorder('A'); cout << "\n";
    postorder('A'); cout << "\n";
}