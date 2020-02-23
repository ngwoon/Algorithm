#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int map[1001][1001];
int area[1001][1001];
int areaNum[500001];
bool visited[1001][1001];
queue<pair<int, int>> que;
stack<pair<int, int>> zone;
vector<int> checkDup;

int row, column;
int num = 1; // 단지 번호

void bfs(int x, int y)
{
	int cnt = 1;

	visited[y][x] = true;
	que.push({ x,y });
	zone.push({ x,y });

	while (!que.empty())
	{
		int nx = que.front().first;
		int ny = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];

			if (tx < 1 || tx > column || ty < 1 || ty > row || map[ty][tx] == 1)
				continue;

			if (visited[ty][tx])
				continue;

			visited[ty][tx] = true;
			cnt++;
			que.push({ tx, ty });
			zone.push({ tx, ty });
		}
	}

	while (!zone.empty())
	{
		int nx = zone.top().first;
		int ny = zone.top().second;
		area[ny][nx] = num;
		zone.pop();
	}

	areaNum[num++] = cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> row >> column;

	for (int i = 1; i < row + 1; i++)
	{
		for (int j = 1; j < column + 1; j++)
		{
			char temp;
			cin >> temp;

			if (temp == '0')
			{
				map[i][j] = 0;
				area[i][j] = -1;
			}
			else
			{
				map[i][j] = 1;
				area[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < row + 1; i++)
	{
		for (int j = 1; j < column + 1; j++)
		{
			if (area[i][j] == -1)
			{
				bfs(j, i);
				for (int k = 1; k < row + 1; k++)
					memset(visited[j], false, column + 1);
			}
		}
	}

	/*cout << endl;
	cout << "area status" << endl;
	for (int i = 1; i < row + 1; i++)
	{
		for (int j = 1; j < column + 1; j++)
			cout << area[i][j];
		cout << endl;
	}
	cout << endl;

	cout << "areaNum status" << endl;
	for (int i = 1; i < num; i++)
		cout << areaNum[i] << " ";
	cout << endl;*/

	for (int i = 1; i < row + 1; i++)
	{
		for (int j = 1; j < column + 1; j++)
		{
			if (map[i][j] == 1)
			{
				int sum = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = j + dx[k];
					int ny = i + dy[k];

					if (nx < 1 || nx > column || ny < 1 || ny > row)
						continue;

					int m;
					for (m = 0; m < checkDup.size(); m++)
					{
						if (area[ny][nx] == checkDup[m])
							break;
					}
					if (m == checkDup.size())
					{
						sum += areaNum[area[ny][nx]];
						checkDup.push_back(area[ny][nx]);
					}
				}
				map[i][j] = (sum + 1) % 10;
				checkDup.clear();
			}
			cout << map[i][j];
		}
		cout << endl;
	}
}