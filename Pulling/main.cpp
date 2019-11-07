#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[1025][1025];
int nSize; // 점점 줄어들 결과행렬의 크기

int main(void)
{
	cin >> nSize;

	for (int i = 1; i < nSize + 1; i++)
	{
		for (int j = 1; j < nSize + 1; j++)
			cin >> matrix[i][j];
	}

	while (nSize != 1)
	{
		int src[4];
		int temp[4];
		int xIndex = 1;
		int yIndex = 1;

		for (int i = 1; i < nSize + 1; i+=2)
		{
			for (int j = 1; j < nSize + 1; j+=2)
			{
				int sIndex = 0;

				src[sIndex++] = matrix[i][j];
				src[sIndex++] = matrix[i][j + 1];
				src[sIndex++] = matrix[i + 1][j];
				src[sIndex] = matrix[i + 1][j + 1];

				for (int k = 0; k < 4; k++)
					temp[k] = src[k];

				sort(temp, temp + 4, greater<int>());

				/*for (int k = 0; k < 4; k++)
					cout << "src[" << k << "] = " << src[k] << "	";
				cout << endl;*/

				if (temp[1] == src[0])
					matrix[yIndex][xIndex++] = src[0];
				else if (temp[1] == src[1])
					matrix[yIndex][xIndex++] = src[1];
				else if (temp[1] == src[2])
					matrix[yIndex][xIndex++] = src[2];
				else
					matrix[yIndex][xIndex++] = src[3];

				if (xIndex > nSize/2)
				{
					xIndex = 1;
					yIndex++;
				}
			}
		}

		nSize /= 2;
	}

	cout << matrix[1][1];

	system("pause");

	return 0;
}