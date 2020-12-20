#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        int n;
        scanf("%d", &n);

        vector<int> blocks(n+2,0);
		for(int i=1; i<=n; ++i)
            scanf("%d", &blocks[i]);

        int tallest = 0;
        for(int i=1; i<=n; ++i) {
            if(blocks[i-1] >= blocks[i] && blocks[i+1] >= blocks[i])
                continue;
            blocks[i] = min(blocks[i-1], blocks[i+1]) + 1;
        }
        for(int i=n; i>=1; --i) {
            if(blocks[i-1] >= blocks[i] && blocks[i+1] >= blocks[i])
                continue;
            blocks[i] = min(blocks[i], min(blocks[i-1], blocks[i+1]) + 1);
            tallest = max(tallest, blocks[i]);
        }
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", tallest);
	}


	return 0;//Your program should return 0 on normal termination.
}