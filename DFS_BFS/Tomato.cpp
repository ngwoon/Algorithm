#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

//������ ���̵��
/*
bfs�� ����ϵ� queue�� 2�����°� ���?

ó�� bfs���� 1�� ���� ã�� �� �ֺ��� 0�� ���� �ε����� q1�� ����.
�� �������� while�� ���� (�������� : q1 q2 �� �� empty)
{
q1���� ������ �� �ּҸ� 1�� �����, �ش� �ּ� �ֺ� �� 0�� ���� �ε����� q2�� ����.
while�� �������� days++(��ĥ �������� üũ�ϴ� ����)
}

q1 �� q2��, �ӽ÷� queue������ ���� while�� �������� ��� ��ü�� �ִ� �������

*/

typedef struct data {
	int z, y, x, day;
}DATA;

int box[101][101][101];
int dx[6] = { 1, 0, 0,-1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };
int dayCnt = 0, notRiped = 0;
int rCnt = 0; // �ᱹ ���� ���� �丶�䰡 �ִ����� Ȯ���ϱ� ���� ����. bfs �߿� 0�� ã���� 1�� ����. �Ŀ� notRiped�� ��
int width, length, height;
queue<DATA> visited;

void bfs()
{
	int z, y, x, day;
	int nx, ny, nz;

	while (!visited.empty())
	{
		z = visited.front().z;
		y = visited.front().y;
		x = visited.front().x;
		day = visited.front().day;
		visited.pop();

		for (int i = 0; i < 6; i++)
		{
			nz = z + dz[i];
			ny = y + dy[i];
			nx = x + dx[i];
			if (nz >= 1 && nz <= height && ny >= 1 && ny <= length && nx >= 1 && nx <= width)
			{
				if (box[nz][ny][nx] == 0)
				{
					box[nz][ny][nx] = 1;
					visited.push({ nz, ny, nx, day + 1 });
					rCnt++;
				}
			}
		}
		dayCnt = max(day, dayCnt);
	}
}

int main(void)
{
	cin >> width >> length >> height;

	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < length + 1; j++)
		{
			for (int k = 1; k < width + 1; k++)
			{
				cin >> box[i][j][k];

				if (box[i][j][k] == 1)
					visited.push({ i, j, k, 0 });
				if (box[i][j][k] == 0)
					notRiped++;
			}
		}
	}

	bfs();

	if (notRiped != rCnt)
		cout << -1;
	else
		cout << dayCnt;

	system("pause");
}