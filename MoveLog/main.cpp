#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

/*
��ǥ����
arr[i][j] �� (i, j)�� �ǹ��Ѵ�. ��, �迭 ����� �ð� �ݴ� �������� 90�� ������
�츮���� �ͼ��� �����ǥ ����� �ȴ�.
*/

typedef struct log {
	int x, y, cnt, state;

	log(int y, int x, int cnt, int state) {
		this->y = y;
		this->x = x;
		this->cnt = cnt;
		this->state = state;
	}
	log() {
		this->y = 0;
		this->x = 0;
		this->cnt = 0;
		this->state = -1;
	}
}Log;

char map[52][52];
bool check[51][51][2]; //�볪�� state�� �����Ͽ� check(���� : 0, ���� : 1)
int mapSize;
Log start, dst;
queue<Log> route; // ���� ��ΰ� �� �� �ִ� �ĺ��� ����

void Up(Log pos)
{
	switch (pos.state)
	{
	case 0 :
		if (pos.y - 1< 1)
			break;
		else if (map[pos.y - 1][pos.x - 1] == '1' || map[pos.y - 1][pos.x] == '1' || map[pos.y - 1][pos.x + 1] == '1')
			break;
		else if (check[pos.y - 1][pos.x][pos.state])
			break;
		else
		{
			check[pos.y - 1][pos.x][pos.state] = true;
			route.push({ pos.y - 1, pos.x, pos.cnt + 1, pos.state });
			break;
		}
	case 1 :
		if (pos.y - 2 < 1 || map[pos.y - 2][pos.x] == '1')
			break;
		else if (check[pos.y - 1][pos.x][pos.state])
			break;
		else
		{
			check[pos.y - 1][pos.x][pos.state] = true;
			route.push({ pos.y - 1, pos.x, pos.cnt + 1, pos.state });
			break;
		}
	}
}
void Down(Log pos)
{
	switch (pos.state)
	{
	case 0:
		if (pos.y + 1 > mapSize)
			break;
		else if (map[pos.y + 1][pos.x - 1] == '1' || map[pos.y + 1][pos.x] == '1' || map[pos.y + 1][pos.x + 1] == '1')
			break;
		else if (check[pos.y + 1][pos.x][pos.state])
			break;
		else
		{
			check[pos.y + 1][pos.x][pos.state] = true;
			route.push({ pos.y + 1, pos.x, pos.cnt + 1, pos.state });
			break;
		}
	case 1:
		if (pos.y + 2 > mapSize || map[pos.y + 2][pos.x] == '1')
			break;
		else if (check[pos.y + 1][pos.x][pos.state])
			break;
		else
		{
			check[pos.y + 1][pos.x][pos.state] = true;
			route.push({ pos.y + 1, pos.x, pos.cnt + 1, pos.state });
			break;
		}
	}
}
void Right(Log pos)
{
	switch (pos.state)
	{
	case 0:
		if (pos.x + 2 > mapSize || map[pos.y][pos.x + 2] == '1')
			break;
		else if (check[pos.y][pos.x + 1][pos.state])
			break;
		else
		{
			check[pos.y][pos.x + 1][pos.state] = true;
			route.push({ pos.y, pos.x + 1, pos.cnt + 1, pos.state });
			break;
		}
	case 1:
		if (pos.x + 1 > mapSize)
			break;
		else if (map[pos.y + 1][pos.x + 1] == '1' || map[pos.y][pos.x + 1] == '1' || map[pos.y - 1][pos.x + 1] == '1')
			break;
		else if (check[pos.y][pos.x + 1][pos.state])
			break;
		else
		{
			check[pos.y][pos.x + 1][pos.state] = true;
			route.push({ pos.y, pos.x + 1, pos.cnt + 1, pos.state });
			break;
		}
	}
}
void Left(Log pos)
{
	switch (pos.state)
	{
	case 0:
		if (pos.x  - 2 < 1 || map[pos.y][pos.x - 2] == '1')
			break;
		else if (check[pos.y][pos.x - 1][pos.state])
			break;
		else
		{
			check[pos.y][pos.x - 1][pos.state] = true;
			route.push({ pos.y, pos.x - 1, pos.cnt + 1, pos.state });
			break;
		}
	case 1:
		if (pos.x - 1 < 1)
			break;
		else if (map[pos.y + 1][pos.x - 1] == '1' || map[pos.y][pos.x - 1] == '1' || map[pos.y - 1][pos.x - 1] == '1')
			break;
		else if (check[pos.y][pos.x - 1][pos.state])
			break;
		else
		{
			check[pos.y][pos.x - 1][pos.state] = true;
			route.push({ pos.y, pos.x - 1, pos.cnt + 1, pos.state });
			break;
		}
	}
}
void Turn(Log pos)
{
	switch (pos.state)
	{
	case 0:
		if (pos.y - 1 < 1 || pos.y + 1 > mapSize)
			break;
		else if (map[pos.y - 1][pos.x - 1] == '1' || map[pos.y - 1][pos.x] == '1' || map[pos.y - 1][pos.x + 1] == '1') // �����ִ� �볪�� ���κ� 1 Ȯ��
			break;
		else if (map[pos.y + 1][pos.x - 1] == '1' || map[pos.y + 1][pos.x] == '1' || map[pos.y + 1][pos.x + 1] == '1') // �����ִ� �볪�� �Ʒ��κ� 1 Ȯ��
			break;
		else if (check[pos.y][pos.x][1])
			break;
		else
		{
			check[pos.y][pos.x][1] = true;
			route.push({ pos.y, pos.x, pos.cnt + 1, 1 }); // ȸ���� state�� queue�� push
			break;
		}
	case 1:
		if (pos.x - 1 < 1 || pos.x + 1 > mapSize)
			break;
		else if (map[pos.y - 1][pos.x - 1] ==  '1' || map[pos.y][pos.x - 1] == '1' || map[pos.y + 1][pos.x - 1] == '1') // ���ִ� �볪�� ���� 1 Ȯ��
			break;
		else if (map[pos.y - 1][pos.x + 1] == '1' || map[pos.y][pos.x + 1] == '1' || map[pos.y + 1][pos.x + 1] == '1') // ���ִ� �볪�� ������ 1 Ȯ��
			break;
		else if (check[pos.y][pos.x][0])
			break;
		else
		{
			check[pos.y][pos.x][0] = true;
			route.push({ pos.y, pos.x, pos.cnt + 1, 0 });
			break;
		}
	}
}

void bfs()
{
	void(*mov[5])(Log);
	Log cur;

	mov[0] = Up;
	mov[1] = Down;
	mov[2] = Left;
	mov[3] = Right;
	mov[4] = Turn;

	check[start.y][start.x][start.state] = true;
	route.push(start);

	while (!route.empty())
	{
		cur = route.front();
		route.pop();

		if (cur.x == dst.x && cur.y == dst.y && cur.state == dst.state)
		{
			cout << cur.cnt;
			return;
		}
		
		for (int i = 0; i < 5; i++)
			mov[i](cur);
	}
	
	/*if (cur.x == dst.x && cur.y == dst.y && cur.state == dst.state)
		cout << cur.cnt;
	else*/
		cout << 0;
}

int main(void)
{
	cin >> mapSize;

	for (int i = 1; i < mapSize + 1; i++)
	{
		for (int j = 1; j < mapSize + 1; j++)
			cin >> map[i][j];
	}

	for (int i = 1; i < mapSize + 1; i++)
	{
		for (int j = 1; j < mapSize + 1; j++)
		{
			if (map[i][j] == 'B')
			{
				if (map[i - 1][j] == 'B' && map[i + 1][j] == 'B')
					start = { i, j, 0, 1 };
				else if (map[i][j - 1] == 'B' && map[i][j + 1] == 'B')
					start = { i, j ,0, 0 };
			}

			if (map[i][j] == 'E')
			{
				if (map[i - 1][j] == 'E' && map[i + 1][j] == 'E')
					dst = { i, j, 0, 1};
				else if (map[i][j - 1] == 'E' && map[i][j + 1] == 'E')
					dst = { i, j, 0, 0};
			}
		}
	}

	bfs();

	system("pause");
}