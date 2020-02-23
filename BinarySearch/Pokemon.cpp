#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

vector<pair<string, int>> names;
vector<pair<int, string>> nums;

string answer;

int main(void) {
    
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        names.push_back({temp, i + 1});
        nums.push_back({i + 1, temp});
    }

    sort(names.begin(), names.end());

    for(int i=0; i<M; i++) {
        string input;
        cin >> input;
        
        int low=0, high=names.size() - 1;
        int mid;

        while(low <= high) {
            mid = (low + high) / 2;

            if(isdigit(input[0])) {
                int num = atoi(input.c_str());
                if(nums[mid].first > num) 
                    high = mid - 1;
                else if(nums[mid].first < num)
                    low = mid + 1;
                else {
                    answer.append(nums[mid].second).append("\n");
                    break;
                }
            } else {
                if(names[mid].first > input)
                    high = mid - 1;
                else if(names[mid].first < input)
                    low = mid + 1;
                else {
                    answer.append(to_string(names[mid].second)).append("\n");
                    break;
                }
            }
        }
    }

    cout << answer;
}