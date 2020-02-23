#include <iostream>
#include <string>

using namespace std;

string list[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void) {
    string word;

    cin >> word;
    int index = 0;
    int len = word.length();
    int answer = 0;
    
    while(index < 8) {
        int tindex = word.find(list[index]);

        if(tindex != string::npos) {
            for(int i=tindex; i<tindex + list[index].size(); i++)
                word[i] = '\0';

            ++answer;
        } else
            ++index;
    }

    for(int i=0; i<len; i++) {
        if(word[i] != '\0')
            ++answer;
    }

    cout << answer;
    return 0;
}