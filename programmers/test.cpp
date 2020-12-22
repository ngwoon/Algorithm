#include <vector>
#include <cstdio>
using namespace std;

int main(void) {
    vector<int> temp;

    temp.push_back(1);

    temp.insert(temp.end(), 3);

    for(int i=0; i<temp.size(); ++i) {
        printf("%d ", temp[i]);
    }
}