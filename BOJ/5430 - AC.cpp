#include <bits/stdc++.h>
using namespace std;

string ans;

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        string order;
        cin >> order;

        int dcnt=0;
        for(int i=0; i<order.size(); ++i) {
            if(order[i] == 'D')
                ++dcnt;
        }

        int n;
        scanf("%d", &n);

        string src;
        cin >> src;

        if(dcnt > n) {
            ans.append("error\n");
            continue;
        }

        src.erase(src.begin());
        src.erase(src.end()-1);
    
        istringstream ss(src);
        string stringBuffer;
        int que[100000];
        int idx=0;
        while(getline(ss, stringBuffer, ',')) {
            que[idx++] = stoi(stringBuffer);
        }
        
        int fidx=0, bidx=n-1;
        int stat=0;
        for(int i=0; i<order.size(); ++i) {
            if(order[i] == 'D')
                stat == 0 ? ++fidx : --bidx;
            else if(order[i] == 'R') {
                if(i != order.size()-1 && order[i+1] == 'R')
                    i = i+1;
                else
                    stat ^= 1;
            }
        }

        ans.append("[");
        if(stat == 0) {
            for(int i=fidx; i<=bidx; ++i) {
                ans.append(to_string(que[i]));
                if(i != bidx)
                    ans.append(",");
            }
        } else {
            for(int i=bidx; i>=fidx; --i) {
                ans.append(to_string(que[i]));
                if(i != fidx)
                    ans.append(",");
            }
        }
        ans.append("]\n");
    }
    cout << ans;
}