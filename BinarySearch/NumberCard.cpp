#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cards[500001];
vector<bool> result;
int N,M;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=1; i<N + 1; i++)
        cin >> cards[i];

    cin >> M;

    sort(cards + 1, cards + N + 1);

    for(int i=1; i<M + 1; i++) {
        int temp;
        cin >> temp;
        cout << binary_search(cards + 1, cards + N + 1, temp) << " ";
    }
}