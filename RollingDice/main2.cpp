#include <iostream>
#include <queue>
#include <vector>

using namespace std;


enum { RIGHT = 1, LEFT, UP, DOWN };
int map[20][20];
queue<int> commands;
vector<int> result;

// dice[0]´Â ¾È¾¸
// °¢°¢ À­¸é, ºÏ, µ¿, ¼­, ³², ¹Ø¸éÀ» ÀÇ¹Ì
int dice[7] = { 0, 0, 0, 0, 0, 0, 0 };
int dx = 0, dy = 0;
int width, height, order;


bool check(int dir)
{
	int nx = 0, ny = 0;
	switch (dir)
	{
	case RIGHT: nx = 1; break;
	case LEFT: nx = -1; break;
	case UP: ny = -1; break;
	case DOWN: ny = 1; break;
	}

	if (dx + nx >= width || dx + nx < 0 || dy + ny >= height || dy + ny < 0)
		return false;
	else
	{
		dx += nx;
		dy += ny;
		return true;
	}
}

void move()
{
	while (!commands.empty())
	{
		if (!check(commands.front()))
		{
			commands.pop();
			continue;
		}

		int temp[7];
		for (int i = 1; i < 7; i++)
			temp[i] = dice[i];

		switch(commands.front())
		{
		case RIGHT :
			dice[1] = temp[4];
			dice[3] = temp[1];
			dice[4] = temp[6];
			dice[6] = temp[3];
			break;
		case LEFT :
			dice[1] = temp[3];
			dice[3] = temp[6];
			dice[4] = temp[1];
			dice[6] = temp[4];
			break;
		case UP :
			dice[1] = temp[5];
			dice[2] = temp[1];
			dice[5] = temp[6];
			dice[6] = temp[2];
			break;
		case DOWN :
			dice[1] = temp[2];
			dice[2] = temp[6];
			dice[5] = temp[1];
			dice[6] = temp[5];
			break;
		}

		if (map[dy][dx] == 0)
			map[dy][dx] = dice[6];
		else {
			dice[6] = map[dy][dx];
			map[dy][dx] = 0;
		}

		commands.pop();
		
		result.push_back(dice[1]);
	}
}

int main(void)
{
	cin >> height >> width >> dy >> dx >> order;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < order; i++)
	{
		int temp;
		cin >> temp;
		commands.push(temp);
	}

	move();
	
	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;

	system("pause");

	return 0;
}