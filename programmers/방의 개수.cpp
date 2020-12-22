#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int solution(vector<int> arrows) {
    int answer = 0;

    map<pair<int, int>, bool> vertex_visited;
    map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;
    
    vertex_visited.insert({{0,0}, -1});
    int cx = 0, cy = 0;
    
    for(int i=0; i<arrows.size(); ++i) {
        int dir = arrows[i];

        for(int j=0; j<2; ++j) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if(vertex_visited[{nx, ny}]) {
                if(!edge_visited[{{nx, ny},{cx, cy}}])
                    ++answer;
            }

            vertex_visited[{nx, ny}] = true;
            edge_visited[{{nx, ny},{cx, cy}}] = true;
            edge_visited[{{cx, cy},{nx, ny}}] = true;

            cx = nx; cy = ny;
        }        
    }

    return answer;
}