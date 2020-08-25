#include <bits/stdc++.h>
using namespace std;

#define IMP 2000000000

int dp[1000001];
int pos[1000001];
int n,k;

int solve(int idx) {
    if(idx == n)
        return 0;
    
    int& ret = dp[idx];
    if(ret == -1) {
        ret = IMP;
        ++idx;
        while(idx <= n && pos[idx]-pos[idx-1] <= k) {
            ret = min(ret, solve(idx) + 1);
            ++idx;
        }   
    }
    return ret;
}

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        scanf("%d", &n);

        memset(dp, -1, n+1);
        for(int i=1; i<=n; ++i)
            scanf("%d", &pos[i]);

        scanf("%d", &k);

        // solve(0);
        int idx=0, cnt=0;
        while(idx != n) {
            int jump=1;
            while(jump + idx <= n && pos[idx+jump] - pos[idx] <= k)
                ++jump;
            if(jump == 1) {
                cnt = -1; break;
            }
            ++cnt;
            idx += (jump-1);
        }

		printf("Case #%d\n", test_case+1);
        printf("%d\n", cnt);   
	}

	return 0;//Your program should return 0 on normal termination.
}