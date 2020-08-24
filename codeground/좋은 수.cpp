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

        vector<int> nums(n);
        for(int i=0; i<n; ++i)
            scanf("%d", &nums[i]);

        unordered_set<int> sum;
        int ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(sum.find(nums[i] - nums[j]) != sum.end()) {
                    ++ans; break;
                }
            }
            for(int j=0; j<=i; ++j)
                sum.insert(nums[j] + nums[i]);
        }

		printf("Case #%d\n", test_case+1);
        printf("%d\n", ans);
	}

	return 0;//Your program should return 0 on normal termination.
}