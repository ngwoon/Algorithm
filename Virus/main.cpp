#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool visited[101];
int cnt = -1;

void dfs(int start)
{
	if (visited[start])
		return;

	int cur = start;
	visited[cur] = true;
	cnt++;
	for (int i = 0; i < adj[cur].size(); i++)
		dfs(adj[cur].at(i));
}

int main(void) 
{
	int v, e;

	cin >> v >> e;

	int start, end;
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end;

		adj[start].push_back(end);
		adj[end].push_back(start);
	}

	dfs(1);

	cout << cnt;

	system("pause");
}