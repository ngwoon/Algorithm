#include <bits/stdc++.h>
using namespace std;

string ans;

int main(void) {
    int t;
    scanf("%d", &t);

    for(int z=0; z<t; ++z) {
        int h,w,n;
        scanf(" %d %d %d", &h, &w, &n);

        int floor = n%h;
        int rIndex = n/h + 1;

        if(floor == 0) { floor = h; --rIndex; }

        ans += to_string(floor);
        if(rIndex < 10) ans += "0" + to_string(rIndex);
        else ans += to_string(rIndex);
        ans += "\n";
    }
    printf("%s", ans.c_str());
}