#include <bits/stdc++.h>
using namespace std;

int pos[1000001];
int n,k;

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        scanf("%d", &n);

        for(int i=1; i<=n; ++i)
            scanf("%d", &pos[i]);

        scanf("%d", &k);

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