#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, bool>> que;
    vector<int> priorCount;

    priorCount.resize(10, 0);
    for(int i=0; i<priorities.size(); ++i) {
        if(i == location)
            que.push({priorities[i], true});
        else
            que.push({priorities[i], false});

        ++priorCount[priorities[i]];
    }

    int order = 0;
    while(1) {
        pair<int, bool> cur = que.front();
        que.pop();

        bool isUrgent = true;
        for(int i=cur.first+1; i<10; ++i) {
            if(priorCount[i] > 0) {
                isUrgent = false;
                break;
            } 
        }
        
        if(isUrgent) {
            ++order;
            --priorCount[cur.first];

            if(cur.second)
                break;
        } else
            que.push(cur);
    }

    return order;
}