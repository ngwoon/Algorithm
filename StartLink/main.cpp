#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[1000001];
int up, down, bSize, start, dst;
queue<pair<int, int>> que; // 현재 층, 버튼 횟수 저장

int dx[2];

void bfs()
{
	visited[start] = true;
	que.push({ start, 0 });

	int npos, cnt;
	while (!que.empty())
	{
		npos = que.front().first;
		cnt = que.front().second;
		que.pop();

		if (npos == dst)
			break;

		int nx;
		for (int i = 0; i < 2; i++)
		{
			nx = npos + dx[i];

			if (nx > bSize || nx < 1)
				continue;
			if (visited[nx])
				continue;

			visited[nx] = true;
			que.push({ nx, cnt + 1 });
		}
	}

	if (npos != dst)
		cout << "use the stairs";
	else
		cout << cnt;
}

int main(void)
{
	cin >> bSize >> start >> dst >> up >> down;

	dx[0] = up;
	dx[1] = -down;

	bfs();
	system("pause");
	return 0;
}