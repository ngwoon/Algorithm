#include <bits/stdc++.h>
using namespace std;

char str[2][300000];
char pattern[2][10];
int pi[2][10];
int plen, slen;
int cnt;

bool findPattern(int dir) {
    int j = 0;
    for(int i=0; i<slen; ++i) {
        while(j > 0 && str[dir][i] != pattern[dir][j])
            j = pi[dir][j-1];
        if(str[dir][i] == pattern[dir][j]) {
            if(j == plen-1) {
                int idx = i + 1;
                while(idx < slen)
                    str[dir][idx-plen] = str[dir][idx++];
                str[dir][idx] = '\0';

                // 반대 방향 str 수정
                idx = slen-(i-plen);
                dir ^= 1;
                while(idx < slen)
                   str[dir][idx-plen] = str[dir][idx++];

                slen -= plen;

                return true;
            }
            else
                ++j;
        }
    }
    return false;
}

void getPI() {
    for(int d=0; d<2; ++d) {
        int j=0;
        for(int i=1; i<plen; ++i) {
            while(j>0 && pattern[d][i] != pattern[d][j])
                j = pi[d][j-1];
            if(pattern[d][i] == pattern[d][j])
                pi[d][i] = ++j;
        }
    }
}

void printResult() {
    printf("%d\n", cnt);
    for(int i=0; i<slen; ++i)
        printf("%c", str[0][i]);
    printf("\n");
}

int main(void) {
    scanf("%s", pattern[0]);
    scanf( "%s", str[0]);
    int plen=strlen(pattern[0]), slen=strlen(str[0]);
    for(int i=0; i<plen; ++i)
        pattern[1][i] = pattern[0][plen-1-i];
    for(int i=0; i<slen; ++i)
        str[1][i] = str[0][slen-1-i];
    
    pattern[1][plen] = '\0';
    str[1][slen] = '\0';

    int n;
    bool isOver = false;
    scanf("%d", &n);
    while(n--) {
        char order;
        scanf(" %c", &order);

        if(!isOver) {
            getPI();

            printf("left pi\n");
            for(int i=0; i<plen; ++i)
                printf("%d ", pi[0][i]);
            printf("\n");

            printf("right pi\n");
            for(int i=0; i<plen; ++i)
                printf("%d ", pi[1][i]);
            printf("\n");

            bool operated;
            if(order == 'L')
                operated = findPattern(0);
            else
                operated = findPattern(1);
            
            if(operated)
                ++cnt;
            else {
                printResult();
                printf("Perfect!");
                isOver = true;
            }
        }
    }
    if(!isOver) {
        printResult();
        getPI();
        bool operated = findPattern(0);
        if(operated)
            printf("%s", operated ? "You Lose!" : "Perfect!");
    }
}