#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum {GO=0, BACK=1, JUMP=2};

vector<int> result;
bool visited[100001];
queue<pair<vector<int>, int>> que;

void bfs(int start, int end)
{
	vector<int> route;
	visited[start] = true;
	route.push_back(start);
	que.push({ route, start });

	int npos, nx;
	vector<int> nroute;
	while (!que.empty())
	{
		npos = que.front().second;
		nroute = que.front().first;
		que.pop();

		if (npos == end)
		{
			route = nroute;
			break;
		}

		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
				case GO:
				{
					nx = npos + 1;
					if (nx > 100000)
						break;
					else if (visited[nx])
						break;
					vector<int> temp = nroute;
					temp.push_back(nx);
					visited[nx] = true;
					que.push({ temp, nx });
					break;
				}
				case BACK:
				{
					nx = npos - 1;
					if (nx < 0)
						break;
					else if (visited[nx])
						break;
					vector<int> temp = nroute;
					temp.push_back(nx);
					visited[nx] = true;
					que.push({ temp, nx });
					break;
				}
				case JUMP:
				{
					nx = npos * 2;
					if (nx > 100000)
						break;
					else if (visited[nx])
						break;
					vector<int> temp = nroute;
					temp.push_back(nx);
					visited[nx] = true;
					que.push({ temp, nx });
					break;
				}
			}
		}
	}

	cout << route.size() - 1 << endl; // 걸린 시간(초)
	
	for (int i = 0; i < route.size(); i++)
		cout << route.at(i) << " ";
}

int main(void)
{
	int n, k;

	cin >> n >> k;

	if (n < k)
	{
		for (int i = 0; i < n; i++)
			visited[i] = true;
	}
	else if (n > k)
	{
		for (int i = 100000; i > n; i--)
			visited[i] = true;
	}

	bfs(n, k);

	system("pause");

	return 0;
}