#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int main(void) {
    int n;
    scanf("%d", &n);

    int maxVal=0;
    for(int i=0; i<n; ++i) {
        int num;
        scanf("%d", &num);
        ++arr[num];
        if(maxVal < num)
            maxVal = num;
    }

    for(int i=1; i<=maxVal; ++i) {
        for(int j=0; j<arr[i]; ++j)
            printf("%d\n", i);
    }
}