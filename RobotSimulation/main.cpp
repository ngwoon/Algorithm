#include <iostream>
#include <tuple>

using namespace std;


//E = 1, N = 2, W = 3, S = 4
//�ð� �ݴ���� ��
enum {EAST = 1, NORTH, WEST, SOUTH};

int robot[101][3];
int width, height, rSize, cSize;// rSize�� �κ� ����, cSize�� ��� ����
tuple<int, char, int> commands[101];

//void printStat()
//{
//	cout << endl;
//	cout << "========================" << endl;
//	for (int j = 1; j < rSize + 1; j++)
//		cout << "Robot " << j << " : " << "(" << robot[j][0] << ", " << robot[j][1] << "),  dir : " << robot[j][2] << endl;
//}

//target : �κ� ��ȣ, kindof : ��� ����, repeat : �ݺ� Ƚ��
void move(int target, char kindof, int repeat)
{
	if (kindof == 'L' || kindof == 'R')
	{
		if (kindof == 'L')
			robot[target][2] += repeat;
		else
		{
			repeat %= 4;
			robot[target][2] = (robot[target][2] + (4 - repeat));
		}

		if (robot[target][2] > 4)
		{
			if (robot[target][2] % 4 == 0)
				robot[target][2] = 4;
			else
				robot[target][2] %= 4;
		}
	}
	else
	{
		for (int i = 0; i < repeat; i++)
		{
			int nx = robot[target][0];
			int ny = robot[target][1];

			int dx = 0, dy = 0;
			switch (robot[target][2])
			{
			case EAST: dx = 1; break;
			case WEST: dx = -1; break;
			case SOUTH: dy = -1; break;
			case NORTH: dy = 1; break;
			}

			//���� ������� Ȯ��
			if (nx + dx > width || nx + dx < 1 || ny + dy > height || ny + dy < 1)
			{
				cout << "Robot " << target << " crashes into the wall";
				exit(0);
			}

			//�ٸ� �κ��� �浹�ϴ��� Ȯ��
			for (int j = 1; j < rSize + 1; j++)
			{
				if (target == j)
					continue;

				if (robot[j][0] == nx + dx && robot[j][1] == ny + dy)
				{
					cout << "Robot " << target << " crashes into robot " << j;
					exit(0);
				}
			}

			robot[target][0] += dx;
			robot[target][1] += dy;
		}
	}
}

int main(void)
{
	char kindof;
	int	target, repeat;

	cin >> width >> height >> rSize >> cSize;

//	atexit(printStat);

	for (int i = 1; i < rSize + 1; i++)
	{
		char temp;
		cin >> robot[i][0] >> robot[i][1] >> temp;
		switch (temp)
		{
		case 'E': robot[i][2] = 1; break;
		case 'W': robot[i][2] = 3; break;
		case 'S': robot[i][2] = 4; break;
		case 'N': robot[i][2] = 2; break;
		}
	}

	for (int i = 1; i < cSize + 1; i++)
	{
		cin >> target >> kindof >> repeat;
		commands[i] = make_tuple(target, kindof, repeat);
	}

	for (int i = 1; i < cSize + 1; i++)
		move(get<0>(commands[i]), get<1>(commands[i]), get<2>(commands[i]));

	cout << "OK";

	return 0;
}