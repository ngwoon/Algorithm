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
		int n;
        scanf("%d", &n);

        vector<int> scores(n);
        for(int i=0; i<n; ++i)
            scanf("%d", &scores[i]);
        
        sort(scores.begin(), scores.end());

        int maxVal=0;
        for(int i=n-1; i>=0; --i) {
            maxVal = max(scores[i] + (n-i), maxVal);
        }

        int ans=0;
        for(int i=0; i<n; ++i) {
            int score = scores[i] + n;
            if(score >= maxVal) {
                ans = n-i;
                break;
            }
        }

		printf("Case #%d\n", test_case+1);
		printf("%d\n", ans);
	}

	return 0;//Your program should return 0 on normal termination.
}