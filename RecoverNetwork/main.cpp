#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF -1000000

using namespace std;

int path[1001];
vector<pair<int, int>> adj[1001];
priority_queue <pair<int, int>> pq; // 순서대로 거리, 현재노드, 이전노드 저장	
int dst[1001];


void dijkstra()
{
	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int index = pq.top().second;
		pq.pop();	

		if (cost > dst[index])
			continue;

		for (int i = 0; i < adj[index].size(); i++)
		{
			int v = adj[index][i].first;
			int w = adj[index][i].second;

			if (dst[v] > dst[index] + w)
			{
				path[v] = index;
				dst[v] = dst[index] + w;
				pq.push({ -dst[v], v });
			}
		}
	}
}

int main(void)
{
	int vertex, edge;

	cin >> vertex >> edge;

	for (int i = 1; i < edge + 1; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;

		adj[v1].push_back({ v2, w });
		adj[v2].push_back({ v1, w });
	}

	dst[1] = 0;

	for (int i = 2; i < vertex + 1; i++)
		dst[i] = -INF;

	dijkstra();

	//출력
	cout << vertex - 1 << endl;
	for (int i = 2; i < vertex + 1; i++)
		cout <<path[i] << " " << i << endl;

	system("pause");

	return 0;
}