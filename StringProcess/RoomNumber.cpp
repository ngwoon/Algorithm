#include <iostream>
#include <string>

using namespace std;

string num;

int src[10] = {0};

int main(void) {
    cin >> num;

    int answer = 0;

    int len = num.length();
    for(int i=0; i<len; i++) {
        if(src[num[i]-'0'] == 0) {
            if(num[i] == '9') {
                if(src[6] != 0) {
                    --src[6];
                    continue;
                }
            } else if(num[i] == '6') {
                if(src[9] != 0) {
                    --src[9];
                    continue;
                }
            }

            ++answer;
            for(int j=0; j<10; j++)
                ++src[j];
            
            --src[num[i]-'0'];
        } else
            --src[num[i]-'0'];
    }

    cout << answer;
    return 0;
}