#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    string output;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> clothes;

        for(int i=0; i<n; ++i) {
            string name, category;
            cin >> name >> category;
            auto iter = clothes.find(category);
            if(iter == clothes.end())
                clothes.insert({category, 1});
            else
                ++iter->second;
        }

        int ans = 1;
        for(auto iter=clothes.begin(); iter!=clothes.end(); ++iter)
            ans *= iter->second + 1;
        
        output.append(to_string(ans-1)).append("\n");
    }

    cout << output;
}