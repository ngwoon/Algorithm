#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <limits.h>

#define INF INT_MAX;

using namespace std;

int V, E, start;
vector<pair<int, int>> adj[20001]; // 노드번호, 가중치
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dst[20001];

void dijkstra()
{
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if (dst[v] < w)
			continue;

		for (int i = 0; i < adj[v].size(); i++)
		{
			int nw = adj[v][i].first;
			int nv = adj[v][i].second;

			if (nw + w < dst[nv])
			{
				dst[nv] = nw + w;
				pq.push({ dst[nv], nv });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	cin >> start;

	for (int i = 1; i < E + 1; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;

		adj[u].push_back({ w,v });
	}

	for (int i = 1; i < V + 1; i++)
	{
		if (i == start)
			dst[i] = 0;
		else
			dst[i] = INF;
	}

	dijkstra();

	for (int i = 1; i < V + 1; i++)
	{
		if (dst[i] == INT_MAX)
			cout << "INF" << endl;
		else
			cout << dst[i] << endl;
	}

	return 0;
}