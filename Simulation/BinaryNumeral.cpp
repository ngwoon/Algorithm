#include <iostream>
#include <vector>

enum { MAX = '1', MIN = '0' };

using namespace std;

char B[1000001];
vector<pair<int, int>> result;

//flag == MIN �̸� ��� ����ǥ�� 0�� ���
//flag == MAX �̸� ��� ����ǥ�� 1�� ���
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

	//���� ���ڸ��� 1�� ��ġ�� ���
	int cnt = 0;
	for (int j = 1; j < nSize + 1; j++)
	{
		if (temp[j] == '1')
			break;
		else
			cnt++;
	}

	// MIN ���� �� B�� ���� 0�� �Ǵ� ���
	if (cnt == nSize)
		return 1;

	//ù 1 �ڿ� 1�� �ϳ��� �����ϴ��� Ȯ��
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