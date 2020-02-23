#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 1000000

using namespace std;

vector<int> adj[101]; //인접리스트
vector<int> kevBkn; //각 사람의 케빈베이컨 합 저장
queue<pair<int, int>> nv;
int dist[101]; //bfs돌면서 각 사람에 대한 케빈베이컨 저장
bool visited[101];

int vertex, edge;

void bfs(int start)
{
	nv.push({ start, 0 });

	while (!nv.empty())
	{
		int cur = nv.front().first;
		int cnt = nv.front().second;
		nv.pop();

		if (visited[cur])
			continue;

		dist[cur] = cnt;
		visited[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++)
			nv.push({ adj[cur].at(i), cnt + 1 });
	}

	int sum = 0;
	for (int i = 1; i < vertex + 1; i++)
		sum += dist[i];

	kevBkn.push_back(sum);
}

int main(void)
{
	cin >> vertex >> edge;

	int start, end;
	for (int i = 0; i < edge; i++)
	{
		cin >> start >> end;

		adj[start].push_back(end);
		adj[end].push_back(start);
	}

	for (int i = 1; i < vertex + 1; i++)
	{
		for (int i = 1; i < vertex + 1; i++)
			dist[i] = INF;

		memset(visited, false, vertex + 1);

		bfs(i);
	}

	int index = -1, min = INF;
	for (int i = 0; i < vertex; i++)
	{
		if (min > kevBkn.at(i))
		{
			min = kevBkn.at(i);
			index = i + 1;
		}
	}

	cout << index;

	system("pause");

	return 0;
}