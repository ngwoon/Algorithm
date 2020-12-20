#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
    setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n,k;
        scanf("%d %d", &n, &k);
        
        vector<int> subjects(n);
        for(int i=0; i<n; ++i)
            scanf("%d", &subjects[i]);
        
        sort(subjects.begin(), subjects.end(), greater<int>());

        int ans=0;
        for(int i=0; i<k; ++i)
            ans += subjects[i];

		printf("Case #%d\n", test_case+1);
		printf("%d\n", ans);
	}

	return 0;//Your program should return 0 on normal termination.
}