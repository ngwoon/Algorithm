#include <iostream>
#include <stack>

enum STAT{ALIVE, ONSEARCH, DEAD};

using namespace std;

int N, P, E;
pair<int, int> info[21];

STAT status[21] = {ALIVE};

stack<pair<int, int>> st;

void btracking() {

    st.push({1, info[1].second});
    status[1] = ONSEARCH;

    while(1) {
        int cur = st.top().first;
        int sum = st.top().second;
        
        for(int i=1; i<N + 1; i++) {
            if(status[i] == ALIVE) {
                st.push(i);
                break;
            }
        }
    }
}

int main(void) {
    cin >> N >> P >> E;

    for(int i=1; i<N + 1; i++) {
        cin >> info[i].first;
        cin >> info[i].second;
    }

    btracking()
}