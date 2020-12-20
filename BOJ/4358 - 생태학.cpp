#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> trees;

    string tree;
    int total=0;
    while(getline(cin, tree)) {
        ++total;
        auto iter = trees.find(tree);
        if(iter == trees.end())
            trees.insert({tree, 1});
        else
            ++iter->second;
    }

    vector<pair<string, int>> res;
    for(auto iter=trees.begin(); iter!=trees.end(); ++iter)
        res.emplace_back(*iter);

    sort(res.begin(), res.end());

    cout << fixed;
    cout.precision(4);
    for(int i=0; i<res.size(); ++i)
        cout << res[i].first << " " << ((float)res[i].second / total) * 100 << endl;
}