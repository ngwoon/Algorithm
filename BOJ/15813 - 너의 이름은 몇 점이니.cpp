#include <bits/stdc++.h>
using namespace std;

string name;
int len;

int main(void) { 
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> len >> name;

    int sum=0;
    for(int i=0; i<len; ++i) sum += name[i];

    printf("%d", sum - 64*len);
}