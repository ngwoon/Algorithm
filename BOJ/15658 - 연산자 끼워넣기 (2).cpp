#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int operators[4];
int n;
int maxVal = -1000000001, minVal = 1000000001;

void dfs(int idx, int res) {
    if(idx == n) {
        maxVal = max(res, maxVal);
        minVal = min(res, minVal);
        return;
    }

    for(int i=0; i<4; ++i) {
        if(operators[i] != 0) {
            int nres = res;
            switch(i) {
                case 0 : nres += num[idx]; break;
                case 1 : nres -= num[idx]; break;
                case 2 : nres *= num[idx]; break;
                case 3 : nres /= num[idx]; break;
            }
            --operators[i];
            dfs(idx+1, nres);
            ++operators[i];
        }
    }
}

int main(void) {
    scanf("%d", &n);
    num.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d" ,&num[i]);

    for(int i=0; i<4; ++i)
        scanf("%d", &operators[i]);

    dfs(1, num[0]);

    printf("%d\n%d", maxVal, minVal);
}