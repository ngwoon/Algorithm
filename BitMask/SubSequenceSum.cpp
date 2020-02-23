#include <stdio.h>
#include <stdbool.h>
#include <math.h>
using namespace std;

int N, S;
int seq[20];
int ans=0;

int main(void) {
    scanf("%d %d", &N, &S);

    for(int i=0; i<N; i++)
        scanf("%d", &seq[i]);

    int stat = 1;
    int end = pow(2, N);
    while(stat != end) {
        int sum=0;
        for(int j=0; j<N; j++) {
            if(stat & (1 << j)) sum += seq[j];
        }
        if(sum == S) ++ans;
        ++stat;
    }

    printf("%d", ans);
}