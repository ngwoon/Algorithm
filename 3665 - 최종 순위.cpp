#include <bits/stdc++.h>
using namespace std;

int lastYear[500];
pair<int, int> changed[25000];
int t,n,m;

int main(void) {
    scanf("%d", &t);
    for(int k=0; k<t; ++k) {
        scanf(" %d", &n);
        for(int i=0; i<n; ++i) scanf(" %d", &lastYear[i]);

        scanf(" %d", &m);
        for(int i=0; i<m; ++i) scanf(" %d %d", &changed[i].first, &changed[i].second);

        
    }
}