#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[2001];
vector<int> destroied;
vector<int> answer;
bool checked[2001];

void solve(int dcSize) {
    
    for(int i=0; i<dcSize; i++) {
        int cur = destroied[i];
        int j;
        for(j=0; j<adj[cur].size(); j++) {
            if(!binary_search(destroied.begin(), destroied.end(), adj[cur][j]))
                break;
        }

        // 자기 자신과 인접한 모든 도시가 파괴된 상태라면
        if(j == adj[cur].size()) {
            answer.push_back(cur);
            checked[cur] = true;
            for(j=0; j<adj[cur].size(); j++)
                checked[adj[cur][j]] = true;
        }


        for(j=0; j<dcSize; j++) {
            if(!checked[destroied[j]]) 
                break;
        }

        // 현재까지의 폭격으로 지도와 같은 상황이 완성되었다면 return
        if(j == dcSize)
            return;
    }
}

int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cSize, rSize;

    cin >> cSize >> rSize;

    for(int i=0; i<rSize; i++) {
        int v1, v2;

        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    int dcSize; //destroied city size

    cin >> dcSize;

    for(int i=0; i<dcSize; i++) {
        int temp;
        cin >> temp;
        destroied.push_back(temp);
    }

    sort(destroied.begin(), destroied.end());

    solve(dcSize);

    // 정답 확인
    int aSize = answer.size();
    int i;
    for(i=0; i<destroied.size(); i++) {
        if(!checked[destroied[i]])
            break;
    }
    if(i != destroied.size())
        cout << -1;
    else {
        cout << aSize << endl;
        for(int i=0; i<aSize; i++)
            cout << answer[i] << " ";
    }
}
