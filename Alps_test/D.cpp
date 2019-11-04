#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> catPos[17];
bool check[17];
int nx = 0, ny = 0; // 현재위치

int main(void)
{
	int cat;
	int sec = 0;
	cin >> cat;

	int x, y;
	for (int i = 1; i < cat + 1; i++)
	{
		cin >> x >> y;
		catPos[i] = { x, y };
	}

	long min = 1000000000;
	int index;
	while (true)
	{
		//현위치에서 가장 가까운 고양이 탐색
		for (int i = 1; i < cat + 1; i++)
		{
			if (check[i])
				continue;
			double dst = pow(abs(x - catPos[i].first), 2) + pow(abs(y - catPos[i].second), 2);
			if (dst < min)
			{
				min = dst;
				index = i;
			}
		}

		sec += abs(x - catPos[index].first) + abs(y - catPos[index].second);

		check[index] = true;

		int k;
		for (k = 1; k < cat + 1; k++)
		{
			if (!check[k])
				break;
		}
		if (k == cat + 1)
			break;
	}

	cout << sec;

	system("pause");
}