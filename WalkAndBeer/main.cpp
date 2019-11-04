#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

/*
편의점 list를 만들어둔다.
위 list는 원점으로부터 거리를 기준으로 오름차순으로 정렬

1. 현재 맥주로 도착 가능한지 검사, 가능하면 happy
2. 불가능하다면, 1000미터 이내의 편의점 중 가장 먼 곳까지 ㄱㄱ
3. 맥주 20병으로 초기화

1,2,3 반복 -> 더 이상 갈 수 있는 편의점이 없는데, 현재 남아있는 맥주로 도착할 수 없다면 sad
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

		//visited 초기화
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