#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

//실패한 아이디어
/*
bfs를 사용하되 queue를 2개쓰는건 어떨까?

처음 bfs들어가면 1인 곳만 찾아 그 주변에 0인 곳의 인덱스를 q1에 저장.
이 다음부터 while문 시작 (종료조건 : q1 q2 둘 다 empty)
{
q1에서 꺼내어 그 주소를 1로 만들고, 해당 주소 주변 중 0인 곳의 인덱스를 q2에 저장.
while문 마지막에 days++(며칠 지났는지 체크하는 변수)
}

q1 과 q2는, 임시로 queue포인터 만들어서 while문 마지막에 계속 교체해 주는 방식으로

*/

typedef struct data {
	int z, y, x, day;
}DATA;

int box[101][101][101];
int dx[6] = { 1, 0, 0,-1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };
int dayCnt = 0, notRiped = 0;
int rCnt = 0; // 결국 익지 못한 토마토가 있는지를 확인하기 위한 변수. bfs 중에 0을 찾으면 1씩 증가. 후에 notRiped와 비교
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