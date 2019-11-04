#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool visited[1001];
vector<int> adj[1001];
vector<int> result;
stack<int> dnv;
queue<int> bnv;

//재귀
void dfs2(int start)
{
	if (visited[start])
		return;

	int cur = start;
	visited[cur] = true;

	result.push_back(cur);
	for (int i = 0; i < adj[cur].size(); i++)
		dfs2(adj[cur].at(i));
}

//스택 사용
void dfs1(int start)
{
	visited[start] = true;
	dnv.push(start);
	result.push_back(start);

	while (!dnv.empty())
	{
		int cur = dnv.top();
		dnv.pop();

		for (int i = 0; i < adj[cur].size(); i++)
		{
			if (visited[adj[cur].at(i)])
				continue;

			visited[adj[cur].at(i)] = true;
			result.push_back(adj[cur].at(i));
			dnv.push(cur);
			dnv.push(adj[cur].at(i));
			break;
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << " ";

	cout << endl;
}

void bfs(int start) 
{
	bnv.push(start);
	visited[start] = true;
	result.push_back(start);

	while (!bnv.empty())
	{
		int cur = bnv.front();
		bnv.pop();

		for (int i = 0; i < adj[cur].size(); i++)
		{
			if (visited[adj[cur].at(i)])
				continue;

			visited[adj[cur].at(i)] = true;
			result.push_back(adj[cur].at(i));
			bnv.push(adj[cur].at(i));
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << " ";

	cout << endl;
}

int main(void)
{
	int v, e, sNode;

	cin >> v >> e >> sNode;

	int start, end;
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}

	for (int i = 1; i < v + 1; i++)
		sort(adj[i].begin(), adj[i].end());

	dfs2(sNode);

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << " ";

	cout << endl;

	memset(visited, false, sizeof(bool) * 1001);
	result.clear();

	bfs(sNode);
	
	system("pause");

	return 0;
}