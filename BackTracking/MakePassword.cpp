#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

/*
    백트래킹
    백준 1759번 - 암호 만들기

    조건을 만족하면 탐색 경로를 출력해야 하므로 스택을 사용하여 경로를 저장했다.
*/

stack<char> stk;
char alph[15];
int L,C;

bool isCons(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return false;
    return true;
}

// cnt : 자음의 갯수
void dfs(int index, int cnt) {
    stk.push(alph[index]);

    if(stk.size() == L) {
        stack<char> temp;
        while(!stk.empty()) {
            char c = stk.top();
            temp.push(c);
            stk.pop();
        }
        while(!temp.empty()) {
            char c = temp.top();
            printf("%c", c);
            stk.push(c);
            temp.pop();
        }
        printf("\n");

        stk.pop();
        return;
    }

    for(int i=index+1; i<C; i++) {
        char nc = alph[i];
        int ncnt = cnt + isCons(nc);

        if(L - ncnt == 0) continue;
        if(L - (stk.size() + 1 - ncnt) < 2) continue;
        dfs(i, ncnt);
    }
    stk.pop();
}

int main(void) {
    scanf("%d %d", &L, &C);

    for(int i=0; i<C; i++)
        scanf(" %c", &alph[i]);
    
    sort(alph, alph + C);
    for(int i=0; i<C; i++)
        dfs(i, isCons(alph[i]));
}