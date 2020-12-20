#include <bits/stdc++.h>
using namespace std;

int scores[100][10];
vector<int> students;

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<10; ++j)
            scanf("%d", &scores[i][j]);
    }

    for(int i=0; i<n; ++i) {
        bool cheat = true;
        for(int j=1; j<=10; ++j) {
            int ans = ((j-1) % 5) + 1;
            if(scores[i][j-1] != ans) {
                cheat = false;
                break;
            }
        }
        if(cheat)
            students.push_back(i + 1);
    }
    for(int i=0; i<students.size(); ++i)
        printf("%d\n", students[i]);
}