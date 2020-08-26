#include <bits/stdc++.h>
using namespace std;

int cnt;
string ans;

void move(int from, int to) {
    ++cnt;
    ans += to_string(from) + " " + to_string(to) + "\n";
}

void hanoi(int plate, int from, int by, int to) {
    if(plate == 1)
        move(from, to);
    else {
        hanoi(plate-1, from, to, by);
        move(from, to);
        hanoi(plate-1, by, from, to);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);

    printf("%d\n", cnt);
    printf("%s", ans.c_str());
}