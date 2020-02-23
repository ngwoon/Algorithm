#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
    string stc;
    stringstream ss;
    int cnt = 0;

    getline(cin, stc);
    
    ss.str(stc);

    string token;
    while(ss >> token)
        ++cnt;

    cout << cnt;
    return 0;
}