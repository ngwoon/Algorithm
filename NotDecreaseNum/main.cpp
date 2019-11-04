#include <iostream>
#include <vector>

#define LL long long

using namespace std;

LL dp[10][65];

int main(void)
{
	vector<LL> result;
	int tSize;
	int nSize;
	LL sum;
	cin >> tSize;

	for (int i = 0; i < tSize; i++)
	{
		sum = 0;

		cin >> nSize;

		for (int j = 0; j < 10; j++)
			fill(dp[j] + 1, dp[j] + nSize + 1, 0);

		//시작 전 dp[1][] 초기화
		for (int j = 0; j < 10; j++)
			dp[j][1] = 1;

		for (int j = 2; j < nSize + 1; j++)
		{
			for (int k = 9; k >= 0; k--)
			{
				for (int m = 9; m >= k; m--)
					dp[k][j] += dp[m][j - 1];
			}
		}

		for (int j = 0; j < 10; j++)
			sum += dp[j][nSize];

		result.push_back(sum);

		/*for (int j = 0; j < 10; j++)
		{
			for (int k = 1; k < nSize + 1; k++)
				cout << dp[j][k] << " ";
			cout << endl;
		}*/
	}

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;

	system("pause");
}