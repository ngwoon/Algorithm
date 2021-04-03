#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> cmap;

    for(int i=0; i<clothes.size(); ++i) {
        auto iter = cmap.find(clothes[i][1]);
        if(iter != cmap.end())
            ++iter->second;
        else
            cmap.insert({clothes[i][1], 1});
    }

    for(auto iter=cmap.begin(); iter!=cmap.end(); ++iter)
        answer *= iter->second + 1;
    

    return answer - 1;
}