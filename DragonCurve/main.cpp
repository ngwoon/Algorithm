#include <iostream>
#include <algorithm>
#include <vector>

/*
������ ��������, ������ ���� ���� Ȥ�� ���η� �����Ѵ�.
���η� �����ϸ� ���� ȸ�� �� y�� -1, ���η� �����ϸ� ���� ȸ�� �� x�� -1�� ��ġ�� �����δ�.

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

		int nx, ny; // �� �� �̵� �� ��ǥ
		int sx, sy; // �� ���븶���� ������
		for (int j = 0; j < g; j++)
		{
			sx = adj.at(adj.size() - 1).first;
			sy = adj.at(adj.size() - 1).second;
			for (int k = adj.size() - 2; k >= 0; k--)
			{
				nx = -(adj.at(k).second - sy) + sx; // adj.at(j).second - sy = y1 (�������� 0�̶� �������� �� �����ġ)
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