#include <iostream>

using namespace std;

enum { EAST = 1, WEST, SOUTH, NORTH };

// L����̸� �ε��� ��������, R����̸� �ε��� ����������
int dir[4] = { EAST, SOUTH, WEST, NORTH };
int robot[101][3];
int width, height, rSize, cSize;// rSize�� �κ� ����, cSize�� ��� ����

//target : �κ� ��ȣ, kindof : ��� ����, repeat : �ݺ� Ƚ��
void move(int target, char kindof, int repeat)
{
	int dirIndex = -1;
	if (kindof == 'L' || kindof == 'R')
	{
		for (int i = 0; i < 4; i++)
		{
			if (dir[i] == robot[target][2])
			{
				dirIndex = i;
				break;
			}
		}

		repeat %= 4;
		if (robot[target][2] == 'L')
			robot[target][2] = dir[(dirIndex + 2 + repeat) % 4];
		else
			robot[target][2] = dir[(dirIndex + repeat) % 4];
	}
	else
	{
		int nx = robot[target][0];
		int ny = robot[target][1];

		int dx = 0, dy = 0;
		switch (robot[target][2])
		{
		case EAST: dx = 1; break;
		case WEST: dx = -1; break;
		case SOUTH: dy = 1; break;
		case NORTH: dy = -1; break;
		}

		//���� ������� Ȯ��
		if (nx + dx > width || nx + dx < 1 || ny + dy > height || ny + dy < 1)
		{
			cout << "Robot " << target << " crashes into the wall" << endl;
			exit(1);
		}

		//�ٸ� �κ��� �浹�ϴ��� Ȯ��
		for (int i = 1; i < rSize + 1; i++)
		{
			if (target == i)
				continue;

			if (robot[target][0] == nx + dx && robot[target][1] == ny + dy)
			{
				cout << "Robot " << target << " crashes into robot " << i << endl;
				exit(1);
			}
		}

		robot[target][0] += nx;
		robot[target][1] += ny;
	}
}

int main(void)
{
	int	target, kindof, repeat;
	cin >> width >> height >> rSize >> cSize;

	for (int i = 1; i < rSize + 1; i++)
		cin >> robot[i][0] >> robot[i][1] >> robot[i][2];

	for (int i = 0; i < cSize; i++)
	{
		cin >> target >> kindof >> repeat;

		move(target, kindof, repeat);
	}

	cout << "OK";

	system("pause");

	return 0;
}