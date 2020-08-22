#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int n,k;
        cin >> n >> k;
        setbuf(stdout, NULL);

        vector<int> left(n);
        vector<int> right(n);
        for(int i=0; i<n; ++i)
            cin >> left[i];
        for(int i=0; i<n; ++i)
            cin >> right[i]; 

        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;
        
        for(int i=0; i<=n; ++i) {
            for(int j=0; j<=n; ++j) {
                if(i == 0 && j == 0)
                    continue;
                if(i != 0)
                    dp[i][j] += dp[i-1][j] + 1;
                if(j != 0)
                    dp[i][j] += dp[i][j-1] + 1;
            }
        }
		
		cout << "Case #" << test_case+1 << endl;
		cout << dp[n][n] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}