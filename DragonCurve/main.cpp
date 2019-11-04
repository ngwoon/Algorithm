#include <iostream>
#include <algorithm>
#include <vector>

/*
시작점 기준으로, 인접한 점은 가로 혹은 세로로 인접한다.
가로로 인접하면 다음 회전 시 y값 -1, 세로로 인접하면 다음 회전 시 x값 -1의 위치로 움직인다.

*/

int dx[] = { 1,1,0 };
int dy[] = { 0,1,1 };

using namespace std;

int map[101][101];
vector<pair<int, int>> adj;
vector<pair<int, int>> npos;

int getSqur()
{
	int cnt = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == 1)
			{
				int nx, ny, k;
				for (k = 0; k < 3; k++)
				{
					nx = j + dx[k];
					ny = i + dy[k];

					if (nx < 0 || nx > 101 || ny < 0 || ny > 101)
						break;
					if (map[ny][nx] != 1)
						break;
				}
				if (k == 3)
					cnt++;
			}
		}
	}

	return cnt;
}

int main(void)
{
	int tSize;
	int result = 0;

	cin >> tSize;

	int x, y, d, g;
	for (int i = 0; i < tSize; i++)
	{
		cin >> x >> y >> d >> g;
		
		map[y][x] = 1;
		adj.push_back({ x, y });
		switch (d)
		{
		case 0: x++; break;
		case 1: y--; break;
		case 2: x--; break;
		case 3: y++; break;
		}
		map[y][x] = 1;
		adj.push_back({ x, y });

		int nx, ny; // 각 점 이동 시 좌표
		int sx, sy; // 각 세대마다의 기준점
		for (int j = 0; j < g; j++)
		{
			sx = adj.at(adj.size() - 1).first;
			sy = adj.at(adj.size() - 1).second;
			for (int k = adj.size() - 2; k >= 0; k--)
			{
				nx = -(adj.at(k).second - sy) + sx; // adj.at(j).second - sy = y1 (기준점을 0이라 가정했을 때 상대위치)
				ny = (adj.at(k).first - sx) + sy; // adj.at(j).first - sx = x1

				map[ny][nx] = 1;
				npos.push_back({ nx, ny });
			}

			while (!npos.empty())
			{
				adj.push_back(npos.front());
				npos.erase(npos.begin());
			}
		}
		
		adj.clear();
	}

	cout << getSqur();

	system("pause");

	return 0;
}