#include <iostream>
#include <vector>

using namespace std;

#define LL long long

LL dp[101];

int main(void) 
{
	int tSize;
	int n;
	vector<LL> result;
	cin >> tSize;

	for (int i = 0; i < tSize; i++)
	{
		cin >> n;

		if (n <= 5)
		{
			if (n <= 3)
				result.push_back(1);
			else if (n <= 5)
				result.push_back(2);
		}
		else
		{
			dp[1] = 1;
			dp[2] = 1;
			dp[3] = 1;
			dp[4] = 2;
			dp[5] = 2;

			for (int i = 6; i < n + 1; i++)
				dp[i] = dp[i - 5] + dp[i - 1];

			result.push_back(dp[n]);
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;

	system("pause");
}