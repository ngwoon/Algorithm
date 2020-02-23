#include <iostream>

using namespace std;

int field[51][51];
int check[51][51];

int main(void)
{
	int width, length, tSize;
	int cab;
	cin >> tSize;

	for (int i = 0; i < tSize; i++)
	{
		cin >> width >> length >> cab;

		for (int j = 1; j < length + 1; j++)
		{
			for (int k = 1; k < width + 1; k++)
				cin >> field[j][k];
		}


	}


}


//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//int field[52][52];
//bool check[52][52];
//queue<pair<int, int>> visited;
//vector<int> result;
//int bugCnt = 0;
//
//void bfs(int column, int raw)
//{
//	check[column][raw] = true;
//	visited.push(make_pair(column, raw));
//
//	int t_column, t_raw;
//	while (!visited.empty())
//	{
//		t_column = visited.front().first;
//		t_raw = visited.front().second;
//		visited.pop();
//
//		if (field[t_column + 1][t_raw] == 1 && !check[t_column + 1][t_raw])
//		{
//			check[t_column + 1][t_raw] = true;
//			visited.push(make_pair(t_column + 1, t_raw));
//		}
//		if (field[t_column - 1][t_raw] == 1 && !check[t_column - 1][t_raw])
//		{
//			check[t_column - 1][t_raw] = true;
//			visited.push(make_pair(t_column - 1, t_raw));
//		}
//		if (field[t_column][t_raw + 1] == 1 && !check[t_column][t_raw + 1])
//		{
//			check[t_column][t_raw + 1] = true;
//			visited.push(make_pair(t_column, t_raw + 1));
//		}
//		if (field[t_column][t_raw - 1] == 1 && !check[t_column][t_raw - 1])
//		{
//			check[t_column][t_raw - 1] = true;
//			visited.push(make_pair(t_column, t_raw - 1));
//		}
//	}
//}
//
//int main(void)
//{
//	int testSize;
//	int width, height;
//	int cSize;
//
//	cin >> testSize;
//
//	for (int k = 0; k < testSize; k++)
//	{
//		cin >> width >> height;
//		cin >> cSize;
//
//		for (int i = 0; i < height + 2; i++)
//		{
//			memset(field[i], 0, sizeof(int) * (width + 2));
//			memset(check[i], false, sizeof(char) * (width + 2));
//		}
//
//		int x, y;
//		for (int i = 0; i < cSize; i++)
//		{
//			cin >> x >> y;
//			field[y + 1][x + 1] = 1;
//		}
//
//		for (int i = 1; i < height + 1; i++)
//		{
//			for (int j = 1; j < width + 1; j++)
//			{
//				if (field[i][j] == 1 && !check[i][j])
//				{
//					bfs(i, j);
//					bugCnt++;
//				}
//			}
//		}
//
//		result.push_back(bugCnt);
//
//		bugCnt = 0;
//
//		for (int i = 0; i < height + 2; i++)
//		{
//			for (int j = 0; j < width + 2; j++)
//				cout << field[i][j];
//
//			cout << endl;
//		}
//	}
//	for (int i = 0; i < result.size(); i++)
//		cout << result.at(i) << endl;
//
//	system("pause");
//}