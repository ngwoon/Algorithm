#include <iostream>
#include <vector>
#include <cstring>

/*
ù ��°, �� ��° ���� ���Ǵ�� ó���ϰ� �� �Ŀ��� k��� �游 �ݴ� ó��
*/

using namespace std;

bool prison[101];

int main(void)
{
	int tSize, pSize;
	int eCnt = 0; // Ż���� ��� �� count
	vector<int> result;

	cin >> tSize;

	for (int i = 0; i < tSize; i++)
	{
		cin >> pSize;

		for (int j = 1; j < pSize + 1; j++)
		{
			for (int k = j; k < pSize + 1; k += j)
			{
				if (j == 2)
					prison[k] = false;
				else
					prison[k] = !prison[k];
			}
		}

		for (int j = 1; j < pSize + 1; j++)
		{
			if (prison[j])
				eCnt++;
		}

		result.push_back(eCnt);
		eCnt = 0;
		memset(prison, false, pSize + 1);

		/*for (int j = 1; j < pSize + 1; j++)
			cout << prison[j] << " ";
		cout << endl;*/
	}

	for (int i = 0; i < result.size(); i++)
		cout << result.at(i) << endl;

	system("pause");
}