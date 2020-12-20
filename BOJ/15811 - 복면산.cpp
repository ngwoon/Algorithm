#include <bits/stdc++.h>
using namespace std;

/*
    15811번 - 북면산

    최대 나올 수 있는 알파벳이 10개이고, 서로 다른 수를 의미하기 때문에 완전탐색으로 풀 수 있다.

    alphaList는 중복을 제거한, 문자열 3개에 등장하는 서로다른 알파벳들이고
    value는 각 알파벳에 해당하는 수, check는 0~9의 수가 배정 되었는가를 표시하는 배열이다.

    처음엔 find, binary_search등의 STL로 풀었으나 시간초과때문에 한참을 고생했다.
    완전탐색 같은 알고리즘을 사용할 땐 웬만하면 printf계열과 전역배열을 사용하여 최대한 시간을 줄이는 방향으로
    풀이하는 것이 낫다.
*/

vector<char> alphaList;
vector<int> value;
vector<bool> check;
char str[3][20];

void dfs(int len) {
    if(len == alphaList.size()) {
        int valToInt[3]={0,0,0};
        for(int i=0; i<3; ++i) { 
            int index=0;
            while(str[i][index] != '\0') {
                valToInt[i] *= 10;
                valToInt[i] += (value[str[i][index]-'A']);
                ++index;
            }
        }

        if(valToInt[0] + valToInt[1] == valToInt[2]) {
            printf("YES"); exit(0); 
        }
        return;
    }

    int index=alphaList[len]-'A';
    for(int i=0; i<=9; ++i) {
        if(check[i]) continue;

        value[index] = i;
        check[i] = true;
        dfs(len+1);
        check[i] = false;
        value[index] = -1;
    }
}

int main(void) {
    for(int i=0; i<3; ++i) scanf("%s", str[i]);

    bool alphaCheck[26];
    memset(alphaCheck, false, sizeof(alphaCheck));
    for(int i=0; i<3; ++i) {
        int index=0;
        while(str[i][index] != '\0') alphaCheck[str[i][index++]-'A']=true;
    }

    for(int i=0; i<26; ++i) {
        if(alphaCheck[i]) alphaList.push_back(i+'A');
    }

    if(alphaList.size() <= 10) {
        value.resize(26, -1);
        check.resize(10, false);
        dfs(0);
    }
    printf("NO");
}