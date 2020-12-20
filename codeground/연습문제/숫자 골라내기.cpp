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
        
        map<int, int> nums;
        for(int i=0; i<n; ++i) {
            int num;
			scanf("%d", &num);

			auto iter = nums.find(num);
			if(iter == nums.end())
				nums.insert({num,1});
			else
				++(iter->second);
		}
		
		vector<int> list;
		for(auto it=nums.begin(); it!=nums.end(); ++it) {
			if(it->second % 2 == 1)
				list.push_back(it->first);
		}

		int ans = list[0];
		for(int i=1; i<list.size(); ++i) {
			ans ^= list[i];
		}
	
		printf("Case #%d\n", test_case+1);
        printf("%d\n", ans);
        
	}

	return 0;//Your program should return 0 on normal termination.
}