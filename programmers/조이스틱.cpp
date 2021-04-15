#include <string>
#include <vector>

using namespace std;

pair<int, int> getNearestIdx(string name, int idx) {
    int n = name.size();

    pair<int, int> right = {-1, 0};
    pair<int, int> left = {-1, 0};
    for(int i=1; i<name.size(); ++i) {
        int nidx = (idx + i) % n;
        if(name[nidx] != 'A') {
            right = {nidx, i};
            break;
        }
    }

    for(int i=1; i<name.size(); ++i) {
        int nidx = (idx - i);
        nidx = nidx < 0 ? nidx + n : nidx;
        if(name[nidx] != 'A') {
            left = {nidx, i};
            break;
        }
    }

    if(right.second > left.second)
        return left;
    else
        return right;
}

int solution(string name) {
    int n = name.size();
    int answer = 0;
    pair<int, int> cur = {0,0};
    while(cur.first != -1) {
        answer += cur.second;

        int gap = name[cur.first] - 'A';
        int rgap = 26 - gap;
        gap = gap < rgap ? gap : rgap;

        answer += gap;
        name[cur.first] = 'A';
        cur = getNearestIdx(name, cur.first);
    }
    return answer;
}