#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	vector<int> coins;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		coins.push_back(temp);
	}

	int cnt = 0;
	int i = coins.size() - 1;
	while (K != 0) {
		if (K >= coins[i]) {
			K -= coins[i];
			++cnt;
		}
		//���� ���ǿ� K�� ���� �� ���� ���� ���� ������ ���������Ƿ�, i�� ������ �Ǵ� ���� ������� �ʴ´�.
		else
			--i;
	}

	cout << cnt;

	return 0;
}