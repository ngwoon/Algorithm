#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/*
동떨어져 있는 그래프 (다른 간선들과 연결되지 않은 그래프) 도 포함시켜야 한다.
*/

enum Color {Red, Black, White};

vector<int> adj[20001];
vector<string> result;
char color[20001];
queue<int> nv;

bool bfs(int vertex)
{	
	int k;
	int num;
	char vc;

	while (true)
	{
		for (k = 1; k < vertex + 1; k++)
		{
			if (color[k] == White)
				break;
		}
		if (k == vertex + 1)
			break;

		nv.push(k);
		color[k] = Red;
		while (!nv.empty())
		{
			num = nv.front();
			vc = color[num];
			nv.pop();

			for (int i = 0; i < adj[num].size(); i++)
			{
				if (color[adj[num].at(i)] != White)
				{
					if (vc == color[adj[num].at(i)])
						return false;
					else
						continue;
				}
				if (vc == Red && color[adj[num].at(i)] == White)
				{
					color[adj[num].at(i)] = Black;
					nv.push(adj[num].at(i));
				}
				else if (vc == Black && color[adj[num].at(i)] == White)
				{
					color[adj[num].at(i)] = Red;
					nv.push(adj[num].at(i));
				}
			}
		}
	}
	return true;
}

int main(void)
{
	int testSize;
	int vertex, edge;
	cin >> testSize;

	int v1, v2;
	for (int i = 0; i < testSize; i++)
	{
		cin >> vertex >> edge;
		
		for (int j = 1; j < vertex + 1; j++)
			color[j] = White;

		for (int j = 1; j < edge + 1; j++)
		{
			cin >> v1 >> v2;
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}

		/*for (int j = 1; j < vertex + 1; j++)
		{
			cout << "adj[" << j << "]" << "   ";

			for (int k = 0; k < adj[j].size(); k++)
				cout << adj[j].at(k) << " ";

			cout << endl;
		}
		for (int j = 1; j < vertex + 1; j++)
		{
			cout << "color[" << j << "] : ";
			if (color[j] == White)
				cout << "White";
			else if (color[j] == Red)
				cout << "Red";
			else
				cout << "Black";
			cout << endl;
		}*/

		bool isBipartite = bfs(vertex);

		if (isBipartite)
			result.push_back("YES");
		else
			result.push_back("NO");

		for (int j = 1; j < vertex + 1; j++)
			adj[j].clear();
	}

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;

	system("pause");

	return 0;
}