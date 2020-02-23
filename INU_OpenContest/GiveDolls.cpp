#include <iostream>
#include <vector>

using namespace std;

pair<int, int> info[21];

vector<int> candidate;
vector<int> dolls;

int N, P, E;
int minVal, maxVal;
int res;

void select() {
    for(int i=1; i<P + 1; i++)
       candidate.push_back(i);

    while(1) {
        minVal = 0;
        maxVal = 0;
        for(int i=0; i<P; i++) {
            minVal += info[candidate[i]].first;
            maxVal += info[candidate[i]].second;
        }
        if(minVal <= E && maxVal >= E) {
            res = E - minVal;
            break;
        }

        ++candidate[P - 1];
        int i;
        for(i=P - 1; i>=1; i--) {
            if(candidate[i] > N - (P - i - 1)) {
                --candidate[i];
                ++candidate[i - 1];
            }
            else
                break;
        }
        
        //모든 경우의 수를 찾아봐도 알맞은 경우가 없을 경우
        if(candidate[0] == N - P + 2) {
            cout << -1;
            exit(0);
        }

        for(int j=i + 1; j < P; j++)
            candidate[j] = candidate[j - 1] + 1;
    }
}

void solve() {
    for(int i=0; i<P; i++)
        dolls.push_back(info[candidate[i]].first);

    for(int i=0; i<P; i++) {
        int gap = info[candidate[i]].second - info[candidate[i]].first;

        if(res > gap) {
            res -= gap;
            dolls[i] = info[candidate[i]].second;
        } else {
            dolls[i] += res;
            res = 0;
            break;
        }
    }
}

int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> P >> E;

    for(int i=1; i<N + 1; i++) {
        cin >> info[i].first;
        cin >> info[i].second;
    }

    select();

    solve();

    int j = 0;
    for(int i=1; i<N + 1; i++) {
        if(candidate[j] == i)
            cout << dolls[j++] << " ";
        else
            cout << 0 << " ";
    }
}   