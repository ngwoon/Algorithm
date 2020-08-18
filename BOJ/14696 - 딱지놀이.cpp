#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    string ans;
    while(n--) {
        int a,b;
        scanf("%d", &a);
        
        vector<int> acard(5, 0), bcard(5, 0);
        for(int i=0; i<a; ++i) {
            int num;
            scanf("%d", &num);
            ++acard[num];
        }
        
        scanf("%d", &b);
        for(int i=0; i<b; ++i) {
            int num;
            scanf("%d", &num);
            ++bcard[num];
        }

        bool isDraw=true;
        for(int i=4; i>=1; --i) {
            if(acard[i] != bcard[i]) {
                ans.append(acard[i] > bcard[i] ? "A" : "B");
                isDraw=false;
                break;
            }
        }
        if(isDraw)
            ans.append("D");

        ans.append("\n");
    }
    printf("%s", ans.c_str());
}