#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <limits.h>
#include <string>

#define INF INT_MAX

using namespace std;

//╩С го аб ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int map[126][126];
int dst[126][126];
priority_queue <pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;
vector<string> result;
int N;

void dijkstra()
{
	dst[1][1] = map[1][1];
	pq.push({ dst[1][1], {1,1} });

	while (!pq.empty())
	{
		int w = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (dst[y][x] < w)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;

			if (dst[ny][nx] > w + map[ny][nx])
			{
				dst[ny][nx] = w + map[ny][nx];
				pq.push({ dst[ny][nx], { nx, ny } });
			}
		}
	}
}

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k = 1;
	while(1)
	{
		cin >> N;

		if (N == 0)
		{
			for (int i = 0; i < result.size(); i++)
				cout << result[i] << endl;

			return 0;
		}

		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				cin >> map[i][j];
				dst[i][j] = INF;
			}
		}

		dijkstra();

		string str("Problem ");
		str.append(to_string(k++));
		str.append(": ");
		str.append(to_string(dst[N][N]));

		result.push_back(str);
	}
}