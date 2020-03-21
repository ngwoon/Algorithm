#include <bits/stdc++.h>
using namespace std;

vector<string> nations;
vector<int> parent;
int n,m;

int Find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m; cin.ignore();
    nations.resize(n);
    for(int i=0; i<n; ++i) {
        string temp;
        getline(cin, temp);
        nations[i] = temp.substr(11, temp.length());
    }

    sort(nations.begin(), nations.end());

    parent.resize(n);
    for(int i=0; i<n; ++i) parent[i] = i;

    for(int i=0; i<m; ++i) {
        string temp;
        getline(cin, temp);
        
        string n1;
        int index=11;
        while(temp[index] != ',') { n1 += temp[index++]; } 
        
        string n2;
        index += 12;
        while(temp[index] != ',') { n2 += temp[index++]; }
        
        int res = temp[index+1]-'0';

        int n1Index = lower_bound(nations.begin(), nations.end(), n1)-nations.begin();
        int n2Index = lower_bound(nations.begin(), nations.end(), n2)-nations.begin();

        int n1p = Find(n1Index);
        int n2p = Find(n2Index);

        // 속국이 자신의 종주국 공격
        if(n1p == n2p) {
            int owner = n1p == n1Index ? n1Index : n2Index;

            if(n2Index == owner && res == 1) {
                parent[n2Index] = n1Index;
                parent[n1Index] = n1Index;
            } else if(n1Index == owner && res == 2) {
                parent[n1Index] = n2Index;
                parent[n2Index] = n2Index;
            }
        }
        else {
            if(res == 1) parent[n2p] = n1p;
            else parent[n1p] = n2p;
        }
    }

    vector<string> ans;
    for(int i=0; i<n; ++i) {
        if(i == parent[i]) ans.push_back(nations[i]);
    }

    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); ++i)
        cout << "Kingdom of " << ans[i] << "\n";
}