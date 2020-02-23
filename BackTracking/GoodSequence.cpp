#include <stdio.h>
#include <stdlib.h>
#include <string>

/*
    백트래킹
    백준 2661 - 좋은수열

    <기존 백트래킹 문제와의 차이점>
    참인 모든 결과를 살펴야 할 필요가 없었다.
    가장 작은 수열을 찾아야 했고, 탐색을 작은 수부터 차례로 진행하기 때문에 조건에 부합하는 결과를 찾으면
    바로 출력하고 종료하면 되었던 문제
*/

using namespace std;

string stk;
int N;

void dfs(char cur) {
    stk += cur;

    // 정답 변수와 현재 수열의 비교
    if(stk.size() == N) {
        printf("%s", stk.c_str());
        exit(0);
    }

    for(char c='1'; c<='3'; c++) {
        // 다음 수를 넣었을 때 나쁜 수열인지 확인 필요 (유망성 검사)
        if(c == stk.back()) continue; // 바로 전 숫자와 같으면 유망하지 않음
        
        string nsq = stk; // next sequence
        nsq += c;

        bool isBad = false;
        for(int i=1; i<=nsq.size()/2; i++) {
            string comp = nsq.substr(nsq.size() - i);
            string target = nsq.substr(nsq.size() - i*2, i);

            // 나쁜 수열이면 isBad = true
            if(!comp.compare(target)) { isBad = true; break; }
        }
        if(isBad) continue;

        dfs(c);
    }
    stk.erase(stk.end() - 1);
}

int main(void ) {
    scanf("%d", &N);
    
    dfs('1');
}
