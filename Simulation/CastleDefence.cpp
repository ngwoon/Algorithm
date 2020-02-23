#include <iostream>
#include <algorithm>
#include <vector>

#define ARCHOR_SIZE 3

using namespace std;

int map[17][16]; // N + 1���� N�࿡ �ִ� ���� �� ������ ���� �� ArrayOutOfIndex ���ܰ� ���� �ʰ� �ϱ� ���� ���
pair<int, int> arpos[ARCHOR_SIZE]; // �ü� ��ġ ����
vector<pair<int, int>> epos; // ���� ��ġ ����
vector<pair<int, int>> atarget; // �ü��� Ÿ������ ���� ���� ����
vector<int> result; // �� ���帶�� ���� �� �� ����
int N, M, D;

bool isEnemyRest()
{
	bool flag = false;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (map[i][j] == 1)
			{
				flag = true;
				break;
			}
		}
	}

	return flag;
}

void getTarget()
{
	for (int i = 0; i < ARCHOR_SIZE; i++)
	{
		vector<pair<int, int>> target;
		int minDst = 100;
		for (int j = 0; j < epos.size(); j++)
		{
			int dst = abs(arpos[i].first - epos[j].first) + abs(arpos[i].second - epos[j].second);

			if (dst > D)
				continue;

			if (minDst > dst)
			{
				target.clear();
				target.push_back({epos[j].first, epos[j].second });
				minDst = dst;
			}
			else if (minDst == dst)
				target.push_back({epos[j].first, epos[j].second });
		}

		if (!target.empty())
		{
			sort(target.begin(), target.end(), less<pair<int, int>>());
			atarget.push_back({ target[0].first, target[0].second });
		}

		target.clear();
	}
}

void attack(int* kills)
{
	getTarget();

	for (int i = 0; i < atarget.size(); i++)
	{
		int ex = atarget[i].first;
		int ey = atarget[i].second;

		//�ߺ� Ÿ�� ���
		if (map[ey][ex] == 1)
		{
			map[ey][ex] = 0;
			(*kills)++;
		}
	}

	atarget.clear();
}

void move()
{
	for (int i = N; i > 0; i--)
	{
		for (int j = 1; j < M + 1; j++)
		{
			map[i + 1][j] = map[i][j];
			map[i][j] = 0;
		}
	}
}

void getEnemyPos()
{
	epos.clear();
	for(int i=1; i<N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (map[i][j] == 1)
				epos.push_back({ j,i });
		}
	}
}

int main(void)
{
	cin >> N >> M >> D;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				epos.push_back({ j, i });
		}
	}

	//�ʱ� �� ���
	int temp[16][16];

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			temp[i][j] = map[i][j];

	//�ü� 3���� ��ġ = i, j, k
	for (int i = 1; i < M - 1; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			for (int k = j + 1; k < M + 1; k++)
			{
				int kills = 0;
				arpos[0] = { i, N + 1 };
				arpos[1] = { j, N + 1 };
				arpos[2] = { k, N + 1 };
				getEnemyPos();

				//���� ����
				while (isEnemyRest())
				{
					attack(&kills);
					move();
					getEnemyPos();
				}

				//�� ����
				for (int i = 1; i < N + 1; i++)
					for (int j = 1; j < M + 1; j++)
						map[i][j] = temp[i][j];

				//���� �� ���� ���� ����
				result.push_back(kills);
			}
		}
	}

	sort(result.begin(), result.end(), greater<int>());

	cout << result[0];

	return 0;
}