//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
////dice[0], dice[1]는 각각 주사위가 남북 / 동서으로 이동 시 지면과 맞닿을 수 있는 면의 집합이다.
////index[]는 dice[0], dice[1]에서 각각 지면에 닿아 있는 면의 인덱스
//
////dice[0]에서 동쪽 이동하면 1->3, 서쪽 이동하면 1->4
////dice[1]에서 남쪽 이동하면 6->2, 북쪽 이동하면 6->5
//
//enum { RIGHT = 1, LEFT, UP, DOWN };
//int map[20][20];
//queue<int> commands;
//vector<int> result;
//int dice[7] = { 0, 0, 0, 0, 0, 0, 0 }; // dice[0]는 안씀
//int* diceDir[3][4] = { { &dice[4], &dice[1],&dice[3],&dice[6] }, { &dice[5],&dice[1],&dice[2],&dice[6] },  { &dice[3],&dice[2],&dice[4],&dice[5] } };
//int dir = 0; // dice배열 중 어떤 행을 이용할 것인지 선택(동/서 이동 : 0, 남/북 이동 : 1)
//int index; //dice[dir]에서 현재 바닥면의 인덱스
//int* side = &dice[6];
//int dx = 0, dy = 0;
//int width, height, order;
//
//bool check(int dir)
//{
//	int nx = 0, ny = 0;
//	switch (dir)
//	{
//	case RIGHT: nx = 1; break;
//	case LEFT: nx = -1; break;
//	case UP: ny = -1; break;
//	case DOWN: ny = 1; break;
//	}
//
//	if (dx + nx >= width || dx + nx < 0 || dy + ny >= height || dy + ny < 0)
//		return false;
//	else
//	{
//		dx += nx;
//		dy += ny;
//		return true;
//	}
//}
//
//void move()
//{
//	while (!commands.empty())
//	{
//		//갈 수 없는 명령 무시
//		if (!check(commands.front()))
//		{
//			commands.pop();
//			continue;
//		}
//
//		if (side == &dice[1] || side == &dice[6])
//		{
//			if (commands.front() == RIGHT || commands.front() == LEFT)
//				dir = 0;
//			else
//				dir = 1;
//		}
//		else if (side == &dice[3] || side == &dice[4])
//		{
//			if (commands.front() == RIGHT || commands.front() == LEFT)
//				dir = 0;
//			else
//				dir = 2;
//		}
//		else
//		{
//			if (commands.front() == RIGHT || commands.front() == LEFT)
//				dir = 2;
//			else
//				dir = 1;
//		}
//		
//
//		// 현재 맞닿아 있는 면(side)이 diceDir에서 어느 인덱스인지 찾기
//		for (int j = 0; j < 4; j++)
//		{
//			if (diceDir[dir][j] == side)
//			{
//				index = j;
//				break;
//			}
//		}
//
//		switch (commands.front())
//		{
//		case RIGHT :
//			index = (index + 1) % 4; break;
//		case LEFT :
//			index = (index + 3) % 4; break;
//		case UP :
//			index = (index + 1) % 4; break;
//		case DOWN :
//			index = (index + 3) % 4; break;
//		}
//
//		side = diceDir[dir][index];
//
//		if (map[dy][dx] == 0)
//			map[dy][dx] = *side;
//		else
//		{
//			*diceDir[dir][index] = map[dy][dx];
//			map[dy][dx] = 0;
//		}
//
//		cout << "==============" << endl;
//		cout << "command : " << commands.front() << endl;
//
//		cout << "dice : ";
//		for (int i = 1; i < 7; i++)
//			cout << dice[i] << " ";
//
//		for (int i = 1; i < 7; i++)
//		{
//			if (side == &dice[i])
//			{
//				cout << "index : " << i << endl;
//				break;
//			}
//		}
//
//		commands.pop();
//
//		index = (index + 2) % 4;
//		result.push_back(*diceDir[dir][index]);
//	}
//}
//
//int main(void)
//{
//	cin >> height >> width >> dy >> dx >> order;
//
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//			cin >> map[i][j];
//	}
//
//	for (int i = 0; i < order; i++)
//	{
//		int temp;
//		cin >> temp;
//		commands.push(temp);
//	}
//
//	move();
//
//	for (int i = 0; i < result.size(); i++)
//		cout << result.at(i) << endl;
//
//	system("pause");
//
//	return 0;
//}