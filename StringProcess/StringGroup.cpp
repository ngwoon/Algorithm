#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> log;

int main(void) {
    int N;
    string word;

    cin >> N;
    
    int answer = 0;
    for(int i=0; i<N; i++) {
        cin >> word;

        log.push_back(word[0]);

        int j;
        for(j=1; j<word.size(); j++) {
            vector<char>::iterator iter = find(log.begin(), log.end(), word[j]);
            if(iter != log.end() && log.back() != word[j])
                break;
            else if(iter == log.end())
                log.push_back(word[j]);
        }
        if(j == word.size())
            ++answer;

        log.clear();
    }

    cout << answer;
    return 0;
}