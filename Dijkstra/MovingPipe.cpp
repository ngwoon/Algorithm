#include <iostream>
#include <algorithm>

using namespace std;

enum STATUS {HORIZONTAL, VERTICAL, DIAGONAL, DEFAULT};

int map[17][17];
int N;
int dp[3][17][17]; // 상태, 경우의 수

int main(void)
{
	int N;

	cin >> N;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			cin >> map[i][j];
	}
	
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < N + 1; i++)
		{
			for (int j = 0; j < N + 1; j++)
				dp[k][i][j] = 0;
		}
	}

	dp[HORIZONTAL][1][2] = 1;

	if (map[N][N] == 1)
		goto EXIT;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 3; j < N + 1; j++)
		{
			if (map[i][j] == 1)
				continue;

			dp[HORIZONTAL][i][j] = dp[HORIZONTAL][i][j - 1] + dp[DIAGONAL][i][j - 1];
			dp[VERTICAL][i][j] = dp[VERTICAL][i - 1][j] + dp[DIAGONAL][i - 1][j];
			if (map[i - 1][j] == 0 && map[i][j - 1] == 0)
				dp[DIAGONAL][i][j] = dp[DIAGONAL][i - 1][j - 1] + dp[HORIZONTAL][i - 1][j - 1] + dp[VERTICAL][i - 1][j - 1];
		}
	}

EXIT:
	
	cout << dp[HORIZONTAL][N][N] + dp[VERTICAL][N][N] + dp[DIAGONAL][N][N];

	return 0;
}