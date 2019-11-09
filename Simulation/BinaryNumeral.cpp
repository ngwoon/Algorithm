#include <iostream>
#include <vector>

enum { MAX = '1', MIN = '0' };

using namespace std;

char B[1000001];
vector<pair<int, int>> result;

//flag == MIN 이면 모든 물음표가 0일 경우
//flag == MAX 이면 모든 물음표가 1일 경우
int getMaxMin(int nSize, int flag)
{
	char temp[1000001];

	for (int j = 1; j < nSize + 1; j++)
	{
		if (B[j] == '?')
			temp[j] = flag;
		else
			temp[j] = B[j];
	}

	//제일 앞자리의 1의 위치를 계산
	int cnt = 0;
	for (int j = 1; j < nSize + 1; j++)
	{
		if (temp[j] == '1')
			break;
		else
			cnt++;
	}

	// MIN 구할 때 B가 전부 0이 되는 경우
	if (cnt == nSize)
		return 1;

	//첫 1 뒤에 1이 하나라도 존재하는지 확인
	int j;
	for (j = cnt + 2; j < nSize + 1; j++)
	{
		if (temp[j] == '1')
			break;
	}

	if (j == nSize + 1)
		return (nSize - cnt) + nSize - 1;
	else
		return (nSize - cnt) + nSize;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tSize;

	cin >> tSize;

	for (int i = 0; i < tSize; i++)
	{
		int nSize;

		cin >> nSize;

		for (int j = 1; j < nSize + 1; j++)
			cin >> B[j];

		result.push_back({ getMaxMin(nSize, MAX) , getMaxMin(nSize, MIN) });
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i].first << " " << result[i].second << endl;

	system("pause");

	return 0;
}