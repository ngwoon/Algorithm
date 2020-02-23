#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/*
dfs로 선수들의 모든 조합을 구한다
선수들이 정확히 반으로 나뉠 때, 각 팀의 능력치를 계산하여 최솟값인지 판단한다.
*/

using namespace std;

int n;
int status[21][21];
vector<int> split;
vector<int> link;
int gap = 10000; //극단적으로 총 20명에서 한 팀의 시너지가 모두 1, 다른 팀이 모두 100이어도 두 팀 능력차가 2000을 넘지 못한다.
bool check[21];


void checkStat()
{
	int spStat = 0;
	int linkStat = 0;
	split.clear();
	link.clear();

	for (int i = 1; i < n + 1; i++)
	{
		if (check[i])
			split.push_back(i);
		else
			link.push_back(i);
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n / 2; j++)
		{
			spStat += (status[split.at(i)][split.at(j)] + status[split.at(j)][split.at(i)]);
			linkStat += (status[link.at(i)][link.at(j)] + status[link.at(j)][link.at(i)]);
		}
	}

	if (gap > abs(spStat - linkStat))
		gap = abs(spStat - linkStat);
}


//len은 선수들이 절반으로 나뉘었는지 판단
void dfs(int num, int len)
{
	if (len == n / 2)
		checkStat();
	else
	{
		//선수 조합
		for (int i = num + 1; i < n + 1; i++)
		{
			check[i] = true;
			dfs(i, len + 1);
		}
	}

	check[num] = false; // 백트래킹
}

int main(void)
{
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
			cin >> status[i][j];
	}

	dfs(1, 0);

	cout << gap;

	system("pause");
}