#include <iostream>
#include <vector>

/*
시뮬레이션 문제
도시 사이거리가 제한거리를 넘을 수 없으므로, 제한거리를 count하는 flag변수를 둔다.
먼저 도시 포탈의 파괴여부를 검사하여 파괴되어있으면 flag++, 이미 존재하면 flag를 0로 초기화한다.
flag == distance의 경우, 포탈이 필요한 시점이므로 포탈 갯수를 세는 cnt를 1 증가시킨다.
*/

using namespace std;

char city[300001];

int main(void)
{
	int tSize, cSize;
	int distance;
	int flag = 0;
	int cnt = 0;
	vector<int> result;
	cin >> tSize;

	for (int i = 0; i < tSize; i++)
	{
		cin >> cSize >> distance;
		for (int j = 1; j < cSize + 1; j++)
			cin >> city[j];

		for (int j = 1; j < cSize + 1; j++)
		{
			if (city[j] == '1')
				flag = 0;
			if (city[j] == '0')
				flag++;
			if (flag == distance)
			{
				flag = 0;
				cnt++;
			}
		}

		result.push_back(cnt);

		flag = 0;
		cnt = 0;
	}

	for (int i = 0; i < result.size(); i++)
		cout << "#" << i + 1 << " " << result.at(i) << endl;

	system("pause");
}