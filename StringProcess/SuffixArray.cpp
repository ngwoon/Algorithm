#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string word;
vector<string> arr;

int main(void) {
    cin >> word;

    int len = word.length();
    arr.push_back(word);
    for(int i=0; i<len - 1; i++) {
        arr.push_back(arr[i]);
        arr[i + 1].erase(arr[i + 1].begin());
    }

    sort(arr.begin(), arr.end());

    len = arr.size();
    for(int i=0; i<len; i++)
        cout << arr[i] << endl;
}
