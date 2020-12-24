#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;


struct node {
    char c;
    vector<struct node*> next;

    node() {
        next.resize(10, NULL);
    }
};

bool solution(vector<string> phone_book) {
    bool answer = true;

    vector<struct node*> start(10, NULL);

    for(int i=0; i<phone_book.size(); ++i) {
        struct node* startNode = start[phone_book[i].c_str()[0] - '0'];
        for(int j=1; j<phone_book[i].size(); ++j) {
            
        }
    }

    return answer;
}

int main(void) {
    vector<string> temp;
    temp.push_back("119");
    temp.push_back("97674223");
    temp.push_back("1195524421");

    printf("%s", solution(temp) ? "true" : "false");
}