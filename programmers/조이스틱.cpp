#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(vector<bool>& visited, string name, int dir, int idx, int sum) {
    int n = name.size();
    bool isAllChecked = true;
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            isAllChecked = false;
            break;
        }
    }
    if(isAllChecked)
        return sum-1;
    
    int gap = name[idx] - 'A';
    int rgap = 26 - gap;
    if(gap > rgap)
        gap = rgap;
    sum += gap;
    visited[idx] = true;

    idx += dir;
    if(idx >= n)
        idx = 0;
    else if(idx < 0)
        idx = n-1;

    return dfs(visited, name, dir, idx, sum+1);
}

int solution(string name) {
    int n = name.size();
    vector<bool> visited(n);

    visited.resize(n, false);
    for(int i=0; i<n; ++i) {
        if(name[i] == 'A')
            visited[i] = true;
    }

    vector<bool> temp(n);
    copy(visited.begin(), visited.end(), temp.begin());
    int a = dfs(temp, name, 1, 0, 0);
    copy(visited.begin(), visited.end(), temp.begin());
    int b = dfs(temp, name, -1, 0, 0);

    return a < b ? a : b;
}