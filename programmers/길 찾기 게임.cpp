#include <bits/stdc++.h>
using namespace std;

pair<int, int> tree[10001];

bool comp(const vector<int>& a, const vector<int>& b) {
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] > b[1];
}

void order(int idx, int type,vector<vector<int>>& answer) {
    if(type == 0) {
        answer[0].push_back()
        order(idx)
    } else {

    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    int n = nodeinfo.size();
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    
    for(int i=0; i<n; ++i)
        tree[i] = {-1, -1};

    for(int i=0; i<n; ++i) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];

        int idx = 1;
        while(tree[idx] != make_pair(-1,-1)) {
            pair<int, int> node = tree[idx];
            if(node.second < x)
                idx = idx * 2 + 1;
            else
                idx = idx * 2;
        }
        tree[idx] = {y,x};
    }



    return answer;
}

int main(void) {

}