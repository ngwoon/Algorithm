#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> src) {
    int answer = 1;

    map<string, int> clothes;

    for(int i=0; i<src.size(); ++i) {
        auto iter = clothes.find(src[i][1]);
        if(iter != clothes.end())
            ++iter->second;
        else
            clothes.insert({src[i][1], 1});
    }

    for(auto iter=clothes.begin(); iter!=clothes.end(); ++iter)
        answer *= iter->second + 1;
    

    return answer - 1;
}