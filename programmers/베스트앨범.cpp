#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int n = genres.size();

    priority_queue<pair<long long, string>, vector<pair<long long, string>>> pq;
    map<string, vector<pair<int, int>>> genreToMusics;
    map<string, long long> genreSum;

    for(int i=0; i<n; ++i) {
        auto it = genreSum.find(genres[i]);
        if(it == genreSum.end()) {
            genreSum.insert({genres[i], plays[i]});

            vector<pair<int, int>> v;
            v.push_back({plays[i], i});
            genreToMusics.insert({genres[i], v});
        } else {
            it->second += plays[i];
            
            auto temp = genreToMusics.find(genres[i]);
            temp->second.push_back({plays[i], i});
        }
    }

    for(auto it=genreToMusics.begin(); it!=genreToMusics.end(); ++it) {
        sort(it->second.begin(), it->second.end(), comp);
    }

    for(auto it=genreSum.begin(); it!=genreSum.end(); ++it) {
        pq.push({it->second, it->first});
    }

    while(!pq.empty()) {
        pair<long long, string> cur = pq.top();
        pq.pop();

        string genre = cur.second;
        auto it = genreToMusics.find(genre);
        vector<pair<int, int>> v = it->second;
        for(int i=0; i<v.size() && i<2; ++i) {
            answer.push_back(v[i].second);
        }
    }
    
    return answer;
}

int main(void) {
    int n;
    scanf("%d", &n);

    vector<string> genres(n);
    vector<int> plays(n);
    for(int i=0; i<n; ++i) {
        cin >> genres[i];
    }
    for(int i=0; i<n; ++i) {
        scanf("%d", &plays[i]);
    }

    auto v = solution(genres, plays);
    for(int i=0; i<v.size(); ++i) {
        printf("%d ", v[i]);
    }
}