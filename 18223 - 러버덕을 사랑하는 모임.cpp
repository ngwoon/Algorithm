#include <bits/stdc++.h>
using namespace std;

/*
    18223번 - 러버덕을 사랑하는 모임

    인형을 나눠줄 사람을 고를 때, 백트래킹으로 유망성 검사를 하며 시간복잡도를 줄여준다.
    나누어줄 사람을 정한 뒤엔, 모든 사람에게 "각 사람의 최소 갯수" 만큼 나누어준 뒤 첫 번째 사람부터 더 줄 수 있는 만큼 주면서
    갯수를 맞추어가면 된다. 갯수를 맞출 때 "해당 사람의 최대 갯수"만 넘어가지 않게 고려해주면 된다.

    스페셜저지 문제이므로 갯수를 맞춰주는 방식은 자유롭다.
*/


vector<pair<int, int>> info;
vector<int> selected;
vector<bool> visited;
int N,P,E;

bool select(int cur, int min, int max) {
    if(cur != -1) selected.push_back(cur);

    if(selected.size() > P) return false;
    if(selected.size() == P) return true;

    for(int i=cur+1; i<N; ++i) {
        if(visited[i]) continue;
        
        int nmin=min+info[i].first;
        int nmax=max+info[i].second;
        if(selected.size() + 1 == P) {
            if(nmin > E || nmax < E) continue;
        }

        visited[i] = true;
        if(select(i, nmin, nmax)) return true;
        visited[i] = false;
    }

    selected.erase(selected.end()-1);
    return false;
}

int main(void) {
    cin >> N >> P >> E;

    info.resize(N);
    for(int i=0; i<N; ++i)
        cin >> info[i].first >> info[i].second;

    visited.resize(N);
    if(!select(-1,0,0)) { cout << -1; exit(0); }

    vector<int> give(N, 0);
    for(int i=0; i<selected.size(); ++i) {
        give[selected[i]]=info[selected[i]].first;
        E -= info[selected[i]].first;
    }
    
    if(E > 0) {
        for(int i=0; i<selected.size(); ++i) {
            int cur = selected[i];
            int canGet = info[cur].second - give[cur];
            if(E > canGet) { give[cur] = info[cur].second; E -= canGet; }
            else { give[cur] += E; break; }
        }
    }

    for(int i=0; i<N; ++i) cout << give[i] << " ";
}