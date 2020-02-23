#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/*
dfs�� �������� ��� ������ ���Ѵ�
�������� ��Ȯ�� ������ ���� ��, �� ���� �ɷ�ġ�� ����Ͽ� �ּڰ����� �Ǵ��Ѵ�.
*/

using namespace std;

int n;
int status[21][21];
vector<int> split;
vector<int> link;
int gap = 10000; //�ش������� �� 20���� �� ���� �ó����� ��� 1, �ٸ� ���� ��� 100�̾ �� �� �ɷ����� 2000�� ���� ���Ѵ�.
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


//len�� �������� �������� ���������� �Ǵ�
void dfs(int num, int len)
{
	if (len == n / 2)
		checkStat();
	else
	{
		//���� ����
		for (int i = num + 1; i < n + 1; i++)
		{
			check[i] = true;
			dfs(i, len + 1);
		}
	}

	check[num] = false; // ��Ʈ��ŷ
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