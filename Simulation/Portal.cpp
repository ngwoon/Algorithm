#include <iostream>
#include <vector>

/*
�ùķ��̼� ����
���� ���̰Ÿ��� ���ѰŸ��� ���� �� �����Ƿ�, ���ѰŸ��� count�ϴ� flag������ �д�.
���� ���� ��Ż�� �ı����θ� �˻��Ͽ� �ı��Ǿ������� flag++, �̹� �����ϸ� flag�� 0�� �ʱ�ȭ�Ѵ�.
flag == distance�� ���, ��Ż�� �ʿ��� �����̹Ƿ� ��Ż ������ ���� cnt�� 1 ������Ų��.
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