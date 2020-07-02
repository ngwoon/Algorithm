#include <bits/stdc++.h>
using namespace std;

vector<int> seq;
int N,Q;

int main(void) {
    scanf("%d %d", &N, &Q);

    seq.resize(N);
    for(int i=0; i<N; ++i) scanf(" %d", &seq[i]);

    int seqSize = seq.size();
    int s=0,e=seqSize-1;
    for(int i=0; i<Q; ++i) {
        int query, num, add;
        scanf(" %d %d", &query, &num);
        if(query == 1) {
            scanf(" %d", &add);

            seq[(s+num-1)%seqSize] += add;
        } else if(query == 2) {
            s = (s + seqSize-num) % seqSize;
            e = (e + seqSize-num) % seqSize;
        } else {
            s = (s+num) % seqSize;
            e = (e+num) % seqSize;
        }
    }

    int index=s;
    while(index != e) {
        printf("%d ", seq[index]);
        index = (index+1) % seqSize;
    }
    printf("%d", seq[e]);
}