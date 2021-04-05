#include <vector>
#include <string>
using namespace std;

#define MAX 1000000007

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> roads;
    roads.resize(n);
    for(int i=0; i<n; ++i)
        roads[i].resize(m, 0);
    
    for(int i=0; i<puddles.size(); ++i) {
        int x = puddles[i][0]-1;
        int y = puddles[i][1]-1;
        roads[y][x] = -MAX;
    }

    bool flag=true;
    for(int i=0; i<m; ++i) {
        if(flag) {
            if(roads[0][i] == -MAX)
                flag=false;
            else
                roads[0][i] = 1;
        }
    }

    flag=true;
    for(int i=0; i<n; ++i) {
        if(flag) {
            if(roads[i][0] == -MAX)
                flag=false;
            else
                roads[i][0] = 1;
        }
    }

    for(int i=1; i<n; ++i) {
        for(int j=1; j<m; ++j) {
            if(roads[i-1][j] == -MAX && roads[i][j-1] == -MAX)
                continue;
            else if(roads[i-1][j] == -MAX)
                roads[i][j] = roads[i][j-1];
            else if(roads[i][j-1] = -MAX)
                roads[i][j] = roads[i-1][j];
            else
                roads[i][j] = (roads[i-1][j] + roads[i][j-1]) % MAX;
        }
    }

    return roads[n-1][m-1];
}