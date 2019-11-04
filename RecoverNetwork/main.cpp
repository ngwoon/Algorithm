#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
int edgeValue[1001][1001];

int main(void)
{
	int vertex, edge;

	cin >> vertex >> edge;

	for (int i = 1; i < vertex + 1; i++)
	{
		for (int j = 1; j < vertex + 1; j++)
			edgeValue[i][j] = 0;
	}

	for (int i = 1; i < edge + 1; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;

		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
		edgeValue[v1][v2] = w;
		edgeValue[v2][v1] = w;
	}
}