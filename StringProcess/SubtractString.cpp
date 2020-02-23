#include <iostream>
#include <string>
#include <vector>

using namespace std;

string A,B;

int main(void) {
    cin >> A >> B;

    int alen = A.size();

    int minVal = 50;
    int compTime = B.size() - alen + 1;
    for(int i=0; i<compTime; i++) {

        int cnt = 0;

        for(int j=0; j<alen; j++) {
            if(A[j] != B[j + i])
                ++cnt;
        }

        if(minVal > cnt)
            minVal = cnt;
    }

    cout << minVal;
}