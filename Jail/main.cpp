#include <iostream>
#include <vector>
#include <cstring>

/*
첫 번째, 두 번째 경우는 조건대로 처리하고 그 후에는 k배수 방만 반대 처리
*/

using namespace std;

bool prison[101];

int main(void)
{
	int tSize, pSize;
	int eCnt = 0; // 탈출한 사람 수 count
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