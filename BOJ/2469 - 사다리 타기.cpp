#include <bits/stdc++.h>
using namespace std;

vector<char> start;
vector<char> target;
vector<char> afterBlank;
vector<char> result;
char answer[26];
int k,n;

void swapElement(int a, int b, vector<char>& vec) {
    vec[a]^=vec[b]; vec[b]^=vec[a]; vec[a]^=vec[b];
}

int main(void) {
    scanf("%d %d", &k, &n);

    target.resize(k);
    start.resize(k);
    for(int i=0; i<k; ++i) {
        scanf(" %c", &target[i]);
        start[i] = i+'A';
    }

    afterBlank.resize(k);
    for(int i=0; i<k; ++i)
        afterBlank[i] = '0'+i;
    
    int isAfterBlank = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<k-1; ++j) {
            char c;
            scanf(" %c", &c);
            if(c == '*') continue;
            else if(c == '-') {
                if(!isAfterBlank)
                    swapElement(j,j+1,start);
                else
                    swapElement(j,j+1,afterBlank);
            }
            else
                isAfterBlank = true;
        }
    }

    result.resize(k);
    for(int i=0; i<k; ++i)
        result[afterBlank[i]-'0'] = target[i];
    
    memset(answer, '*', k-1);
    for(int i=0; i<k-1; ++i) {
        if(start[i] != result[i]) {
            if(start[i+1] == result[i] && start[i] == result[i+1]) {
                answer[i] = '-';
                swapElement(i,i+1,start);
            }
            else {
                for(int i=0; i<k-1; ++i)
                    printf("x");
                exit(0);
            }
        }
    }
    for(int i=0; i<k-1; ++i)
        printf("%c", answer[i]);
}