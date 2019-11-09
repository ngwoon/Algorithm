#include <iostream>
#include <vector>
#include <algorithm>

/*
가장 적은 자리로 많은 사람을 앉히는 방법은, 되도록 많은 사람들의 빈 공간이 서로
겹치게끔 배치하는 것이다.
예를 들어 7번의 왼쪽에 5번 사람이 있다면, 7번의 왼쪽 공백 7자리와 5번의 오른쪽 공백 5자리가 겹치면
7번의 공백으로 5번의 공백을 메꿀 수 있다.

풀이 방법
사람 번호를 받고, 오름차순으로 정렬하여 총 좌석수를 저장하는 sum변수를 둔다.
for문을 시작하여 sum += (사람 번호 + 1)연산을 한다.
마지막 차례엔 그 사람의 번호만큼만 더해주면 총 좌석수를 구할 수 있다.
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