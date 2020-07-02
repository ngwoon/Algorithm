    #include <bits/stdc++.h>
    using namespace std;

    int N;

    int main(void) {
        scanf("%d", &N);

        int sum=0;
        int cnt=1;
        while(sum < N) sum += cnt++;

        --cnt;
        sum -= cnt;

        int a = cnt;
        int b = 1;

        int rest = N-sum;
        while(--rest) { --a; ++b; }
        printf("%d %d", a, b);
    }