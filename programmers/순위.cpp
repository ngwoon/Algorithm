#include <string>
#include <vector>
using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<bool>> adj;
    adj.resize(n+1, vector<bool>(n+1, false));

    for(int i=0; i<results.size(); ++i)
        adj[results[i][0]][results[i][1]] = true;
    
    for(int k=1; k<=n; ++k) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                if(adj[i][k] && adj[k][j])
                    adj[i][j] = true;
            }
        }
    }

    for(int i=1; i<=n; ++i) {
        int cnt=0;
        for(int j=1; j<=n; ++j) {
            if(i == j) continue;
            if(adj[i][j] || adj[j][i])
                ++cnt;
        }
        if(cnt == n-1)
            ++answer;
    }
    
    return answer;
}