#include <iostream>
#include <vector>

using namespace std;

enum { UP=0,DOWN, RIGHT, LEFT };

pair<int, bool> map[20][20];
int N;

void move(int dir)
{
	switch (dir)
	{
	case UP :
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				if (map[i][j].first != 0)
				{
					for (int k = 0; k < N; k++)
					{
						if (map[i][j].first == 0)
						{
							map[k][j].first = map[i][j].first;
							map[i][j].first = 0;
							break;
						}
					}
				}
			}
		}
		break;
	case DOWN :
		for (int j = 0; j < N; j++)
		{
			for (int i = N; i >= 0; i--)
			{
				if (map[i][j].first != 0)
				{
					for (int k = N; k >= 0; k--)
					{
						if (map[i][j].first == 0)
						{
							map[k][j].first = map[i][j].first;
							map[i][j].first = 0;
							break;
						}
					}
				}
			}
		}
		break;
	case RIGHT :
		for (int i = 0; i < N; i++)
		{
			for (int j = N; j >= 0; j--)
			{
				if (map[i][j].first != 0)
				{
					for (int k  = N; k >= 0; k--)
					{
						if (map[i][j].first == 0)
						{
							map[i][k].first = map[i][j].first;
							map[i][j].first = 0;
							break;
						}
					}
				}
			}
		}
		break;
	case LEFT :
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j].first != 0)
				{
					for (int k = 0; k < N; k++)
					{
						if (map[i][j].first == 0)
						{
							map[i][k].first = map[i][j].first;
							map[i][j].first = 0;
							break;
						}
					}
				}
			}
		}
		break;
	}
}
void merge(int dir)
{
	switch (dir)
	{
	case UP :
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N - 1; i++)
			{
				if (map[i][j].first != 0)
				{
					if (map[i][j].first == map[i + 1][j].first)
					{
						map[i][j].first *= 2;

						for (int m = i + 2; m < N - 1; m++)
							map[m][j].first = map[m + 1][j].first;
						map[N - 1][j].first = 0;
						break;
					}
				}
			}
		}
		break;
	case DOWN :
		for (int j = 0; j < N; j++)
		{
			for (int i = N; i >= 1; i++)
			{
				if (map[i][j].first != 0)
				{
					if (map[i][j].first == map[i - 1][j].first)
					{
						map[i][j].first *= 2;

						for (int m = i - 2; m >= 0; m--)
							map[m][j] = map[m - 1][j];
						break;
					}
				}
			}
		}
		break;
	case RIGHT :
	case LEFT :
	}
}
bool check()
{

}
int getMax()
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (max < map[i][j].first)
				max = map[i][j].first;
		}
	}

	return max;
}


int main(void)
{
	vector<int> result;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j].first;
			map[i][j].second = false;
		}
	}

	// i, j, k, m, n은 5번 이동하는 방향
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int m = 0; m < 5; m++)
				{
					for (int n = 0; n < 5; n++)
					{
						int dir[5] = { i,j,k,m,n };
						
						for (int d = 0; d < 5; d++)
						{
							move(dir[d]);
							merge(dir[d]);
							if (check())
								break;

							result.push_back(getMax());
						}
					}
				}
			}
		}
	}

	return 0;
}