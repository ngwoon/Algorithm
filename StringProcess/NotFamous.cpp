#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> notHeard;
vector<string> noFame;

int main(void) {
    int N, M;

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        notHeard.push_back(temp);        
    }

    sort(notHeard.begin(), notHeard.end());

    for(int i=0; i<M; i++) {
        string temp;
        cin >> temp;

        if(binary_search(notHeard.begin(), notHeard.end(), temp))
            noFame.push_back(temp);
    }

    sort(noFame.begin(), noFame.end());

    int len = noFame.size();
    cout << len << endl;
    for(int i=0; i<len; i++)
        cout << noFame[i] << endl;
}