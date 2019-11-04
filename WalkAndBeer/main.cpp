#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

/*
������ list�� �����д�.
�� list�� �������κ��� �Ÿ��� �������� ������������ ����

1. ���� ���ַ� ���� �������� �˻�, �����ϸ� happy
2. �Ұ����ϴٸ�, 1000���� �̳��� ������ �� ���� �� ������ ����
3. ���� 20������ �ʱ�ȭ

1,2,3 �ݺ� -> �� �̻� �� �� �ִ� �������� ���µ�, ���� �����ִ� ���ַ� ������ �� ���ٸ� sad
*/


vector<string> result;
queue<int> ncv;
pair<int, int> map[103];
vector<int> adj[103];
bool visited[103];
int nx, ny, mapIndex = 0;

bool getDst(pair<int, int> start, pair<int, int> end)
{
	if (abs(start.first - end.first) + abs(start.second - end.second) <= 1000)
		return true;
	else
		return false;
}

void bfs(int cSize)
{
	int dx = map[cSize].first;
	int dy = map[cSize].second;

	visited[1] = true;
	ncv.push(1);

	while (!ncv.empty())
	{
		mapIndex = ncv.front();
		nx = map[mapIndex].first;
		ny = map[mapIndex].second;
		ncv.pop();

		if (getDst(map[mapIndex], map[cSize]))
		{
			nx = dx;
			ny = dy;
			break;
		}
			
		for (int i = 0; i < adj[mapIndex].size(); i++)
		{
			if (!visited[adj[mapIndex].at(i)])
			{
				visited[adj[mapIndex].at(i)] = true;
				ncv.push(adj[mapIndex].at(i));
			}
		}
	}

	if (nx == dx && ny == dy)
		result.push_back("happy");
	else
		result.push_back("sad");

	while (!ncv.empty())
		ncv.pop();
}

void initAdj(int cSize)
{
	for (int i = 1; i < cSize + 1; i++)
	{	
		for (int j = i - 1; j > 0; j--)
		{
			if (getDst(map[i], map[j]))
				adj[i].push_back(j);
		}
		for (int k = i + 1; k < cSize + 1; k++)
		{
			if (getDst(map[i], map[k]))
				adj[i].push_back(k);
		}
	}
}

int main(void)
{
	int tSize, cSize;

	cin >> tSize;

	for (int i = 0; i < tSize; i++)
	{
		cin >> cSize;

		cSize += 2;

		for (int j = 1; j < cSize + 1; j++)
			cin >> map[j].first >> map[j].second;

		initAdj(cSize);

		/*cout << "============" << endl;
		for (int j = 1; j < cSize + 1; j++)
		{
			cout << j << " : ";
 			for (int k = 0; k < adj[j].size(); k++)
				cout << adj[j].at(k) << " ";

			cout << endl;
		}
		cout << "============" << endl;*/

		//visited �ʱ�ȭ
		memset(visited, false, cSize + 1);

		bfs(cSize);

		for (int j = 1; j < cSize + 1; j++)
		{
			while (!adj[j].empty())
				adj[j].pop_back();
		}
	}

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;

	system("pause");

	return 0;
}