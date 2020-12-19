#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<pair<int, int>> que;
    int time = 1;
    int idx = 1;
    int bridge_weight = truck_weights[0];
    que.push({truck_weights[0], 0});
    
    while(!que.empty()) {
        // 다리를 빠져나가는 트럭이 있는지 확인
        if(time - que.front().second == bridge_length) {
            bridge_weight -= que.front().first;
            que.pop();
        }
        
        // 다리에 새로 들어올 수 있는 트럭이 있는지 확인
        if(idx < truck_weights.size() && que.size() < bridge_length && bridge_weight + truck_weights[idx] <= weight) {
            que.push({truck_weights[idx], time});
            bridge_weight += truck_weights[idx++];
        }

        ++time;
    }

    answer = time;

    return answer;
}