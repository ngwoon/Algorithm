#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[5000];
int pi[5000];
int len;

int getPI(int idx) {
    char patt[5000];
    strcpy(patt, str + idx);

    int plen = strlen(patt), j=0;
    for(int i=1; i<plen; ++i) {
        while(j>0 && patt[i] != patt[j])
            j = pi[j-1];
        if(patt[i] == patt[j])
            pi[i] = ++j;
    }

    int maxVal = 0;
    for(int i=0; i<plen; ++i)
        maxVal = maxVal < pi[i] ? pi[i] : maxVal;
    
    return maxVal;
}

int main(void) {
    scanf("%s", str);

    int maxVal = 0;
    len = strlen(str);
    for(int i=0; i<len; ++i) {
        memset(pi, 0, len-i);
        int res = getPI(i);
        maxVal = maxVal < res ? res : maxVal;
    }
    printf("%d", maxVal);
}