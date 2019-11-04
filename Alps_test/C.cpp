//#include <iostream>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//
//typedef struct info {
//	int y, x, cnt, tileIndex;
//	info(int x, int y, int cnt, int tileIndex) {
//		this->x = x;
//		this->y = y;
//		this->cnt = cnt;;
//		this->tileIndex = tileIndex;
//	}
//}INFO;
//
////상, 하, 좌 우
//int dx[] = { 0, 0, -1, 1 };
//int dy[] = { 1, -1, 0, 0 };
//
//int x = 1, y = 1; //주인공 좌표
//int cnt = 0;
//char str[27];
//char map[101][101];
//bool check[101][101];
//int length, width, strSize, maxCnt = 0;
//stack<INFO> nt;
//
//
//void dfs()
//{
//	int nx, ny, tileIndex, nCnt;
//	int tx, ty;
//	check[1][1] = true;
//	if(strSize == 1)
//		nt.push({ 1, 1, 1, 1 % strSize + 1 });
//	else
//		nt.push({ 1, 1, 0, 1 % strSize + 1 });
//
//	while (!nt.empty())
//	{
//		tx = nt.top().x;
//		ty = nt.top().y;
//		tileIndex = nt.top().tileIndex;
//		nCnt = nt.top().cnt;
//		nt.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			nx = tx + dx[i];
//			ny = ty + dy[i];
//
//			if (nx < 1 || nx > width || ny < 1 || ny > length)
//				continue;
//			if (check[ny][nx])
//				continue;
//			
//			if (map[ny][nx] == str[tileIndex])
//			{
//				if (str[strSize] == map[ny][nx] && check[ny][nx])
//				{
//					cout << "무한루프" << endl;
//					cout << -1;
//					return;
//				}
//
//				check[ny][nx] = true;
//				cout << "push (" << nx << ", " << ny << ")" << endl;
//				if (map[ny][nx] == str[strSize]) //문자열 끝까지 왔으면 그곳으로 위치 업데이트, 따라간 횟수 증가
//				{
//					x = nx;
//					y = ny;
//					maxCnt = max(nCnt + 1, maxCnt);
//
//					nt.push({ tx, ty, nCnt, tileIndex });
//					nt.push({ nx, ny, nCnt + 1, tileIndex % strSize + 1 });
//				}
//				else
//				{
//					nt.push({ tx, ty, nCnt, tileIndex });
//					nt.push({ nx, ny, nCnt, tileIndex % strSize + 1 });
//				}
//			}
//		}
//	}
//
//	if (maxCnt == 0)
//	{
//		cout << -1;
//		return;
//	}
//	else
//	{
//		cout << maxCnt << endl;
//		cout << y << " " << x;
//	}
//}
//
////
////void bfs()
////{
////	int nx, ny, tileIndex; // 이동 가능한 x,y 계산 시 필요
////	int tx, ty; // 큐에서 나온 x,y 저장
////	check[1][1] = true;
////	nt.push({ 1, 1, 2 });
////
////	while (!nt.empty())
////	{
////		tx = get<0>(nt.front());
////		ty = get<1>(nt.front());
////		tileIndex = get<2>(nt.front());
////		nt.pop();
////
////		for (int i = 0; i < 4; i++) 
////		{
////			nx = tx + dx[i];
////			ny = ty + dy[i];
////
////			if (nx < 1 || nx > width || ny < 1 || ny > length)
////				continue;
////			if (map[ny][nx] == str[tileIndex])
////			{
////				if (check[ny][nx] && map[ny][nx] == str[1]) // 이미 방문했는데 그곳이 문자열 처음부분이면 무한루프 가능성
////				{
////					cout << "무한루프" << endl;
////					cout << -1;
////					return;
////				}
////				if (map[ny][nx] == str[strSize]) //문자열 끝까지 왔으면 그곳으로 위치 업데이트, 따라간 횟수 증가
////				{
////					x = nx;
////					y = ny;
////					cnt++;
////				}
////
////				check[ny][nx] = true;
////				cout << "push (" << nx << ", " << ny << ")" << endl;
////				nt.push({ nx, ny, tileIndex % strSize + 1 });
////			}
////		}
////	}
////
////	if (x == 1 && y == 1) //bfs가 끝났는데 위치 업데이트가 안되었다면 문자열 한 사이클도 못간 것. 보물 없음 판단
////	{
////		cout << "보물 없음" << endl;
////		cout << -1;
////		return;
////	}
////	else
////	{
////		cout << cnt << endl;
////		cout << y << " " << x;
////		return;
////	}
////}
//
//int main(void)
//{	
//	cin >> length >> width >> strSize;
//
//	for (int i = 1; i < strSize + 1; i++)
//		cin >> str[i];
//
//	for (int i = 1; i < length + 1; i++)
//	{
//		for (int j = 1; j < width + 1; j++)
//			cin >> map[i][j];
//	}
//
//	if (length == 1 && width == 1)
//	{
//		if (str[1] == map[1][1])
//		{
//			cout << 1 << endl;
//			cout << 1 << " " << 1;
//		}
//		else
//			cout << -1;
//
//		return  0;
//	}
//
//	dfs();
//
//	system("pause");
//	
//	return 0;
//}