#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

typedef struct info {
    int x;
    int y;
    vector<pair<int, int>> linked;
}INFO;

bool comp(const INFO& a, const INFO& b) {
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int solution(vector<int> arrows) {
    int answer = 0;

    map<pair<int, int>, vector<pair<int, int>>> visited;
    visited.insert({{0, 0}, *new vector<pair<int, int>>});
    int cx = 0, cy = 0;
    
    for(int i=0; i<arrows.size(); ++i) {
        int dir = arrows[i];
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        
        auto miter = visited.find({nx, ny});
        if(miter != visited.end()) {
            auto viter = lower_bound(miter->second.begin(), miter->second.end(), make_pair(cx, cy));
            if(viter == miter->second.end() || !(viter->first == cx && viter->second == cy)) {
                // printf("nx : %d, ny : %d, cx : %d, cy : %d\n", nx, ny, cx, cy);
                ++answer;
                miter->second.insert(viter, {cx, cy});
                vector<pair<int, int>>& rv = visited.find({cx, cy})->second;
                auto rviter = lower_bound(rv.begin(), rv.end(), make_pair(nx, ny));
                rv.insert(rviter, {nx, ny});
            }
        } else {
            vector<pair<int, int>>* nv = new vector<pair<int, int>>;
            nv->push_back({cx, cy});
            visited.insert({{nx, ny}, *nv});

            vector<pair<int, int>>& rv = visited.find({cx, cy})->second;
            auto rviter = lower_bound(rv.begin(), rv.end(), make_pair(nx, ny));
            rv.insert(rviter, {nx, ny});
        }

        cx = nx; cy = ny;
    }

    for(auto iter=visited.begin(); iter!=visited.end(); ++iter) {
        printf("(%d, %d) -> ", iter->first.first, iter->first.second);
        for(int i=0; i<iter->second.size(); ++i) {
            printf("(%d, %d) ", iter->second[i].first, iter->second[i].second);
        }
        printf("\n");
    }

    return answer;
}

int main(void) {
    int temp[20] = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0};
    vector<int> arrows(18);

    for(int i=0; i<18; ++i)
        arrows[i] = temp[i];

    printf("%d", solution(arrows));
}