#include <iostream>
#include <vector>
#include <algorithm>

/*
���� ���� �ڸ��� ���� ����� ������ �����, �ǵ��� ���� ������� �� ������ ����
��ġ�Բ� ��ġ�ϴ� ���̴�.
���� ��� 7���� ���ʿ� 5�� ����� �ִٸ�, 7���� ���� ���� 7�ڸ��� 5���� ������ ���� 5�ڸ��� ��ġ��
7���� �������� 5���� ������ �޲� �� �ִ�.

Ǯ�� ���
��� ��ȣ�� �ް�, ������������ �����Ͽ� �� �¼����� �����ϴ� sum������ �д�.
for���� �����Ͽ� sum += (��� ��ȣ + 1)������ �Ѵ�.
������ ���ʿ� �� ����� ��ȣ��ŭ�� �����ָ� �� �¼����� ���� �� �ִ�.
*/

using namespace std;

int pNum[10001];

int main(void)
{
	int testSize;
	int pSize;
	int sum = 0;
	vector<int> result;

	cin >> testSize;

	for (int i = 0; i < testSize; i++)
	{
		cin >> pSize;

		for (int j = 1; j < pSize + 1; j++)
			cin >> pNum[j];


		sort(pNum + 1, pNum + pSize + 1);

		sum = pNum[1] + 1;
		for (int j = 2; j < pSize + 1; j++)
			sum += (pNum[j] + 1);

		sum += pNum[pSize];

		result.push_back(sum);

		sum = 0;
	}

	for (int i = 0; i < result.size(); i++)
		cout << "#" << i + 1 << " " << result.at(i) << endl;

	system("pause");
}