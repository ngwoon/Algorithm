#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

typedef struct info {
    int x;
    int y;
    vector<bool> dir;

    info(int _x, int _y): x(_x), y(_y) {
        dir.resize(8, false);
    }
    info() {
        dir.resize(8, false);
    }
}INFO;

bool comp(const INFO& a, const INFO& b) {
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int solution(vector<int> arrows) {
    int answer = 0;

    vector<INFO> visited;
    visited.push_back({0, 0});
    int cx = 0, cy = 0;
    
    for(int i=0; i<arrows.size(); ++i) {
        int dir = arrows[i];
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        
        auto iter = binary_search(visited.begin(), visited.end(), INFO{nx, ny}, comp);

        // for(int j=0; j<visited.size(); ++j) {
        //     cout << "x : " << visited[j].x << " y : " << visited[j].y << " dir : " << visited[j].dir << endl;
        // }
        // cout << endl;

        if(binary_search(visited.begin(), visited.end(), INFO{nx, ny}, comp)) {
            auto iter = lower_bound(visited.begin(), visited.end(), INFO{nx, ny}, comp);
            if(!iter->dir[dir]) {
                ++answer;
                iter->dir[dir] = true;

                iter = lower_bound(visited.begin(), visited.end(), INFO{cx, cy}, comp);
                iter->dir[(dir + 4) % 8] = true;
            }
        } else {
            INFO newLine(nx, ny);
            newLine.dir[dir] = true;
            INFO rnewLine(cx, cy);
            rnewLine.dir[(dir + 4) % 8] = true;

            visited.insert(lower_bound(visited.begin(), visited.end(), newLine, comp), newLine);
            visited.insert(lower_bound(visited.begin(), visited.end(), rnewLine, comp), rnewLine);
        }

        cx = nx; cy = ny;
    }

    return answer;
}