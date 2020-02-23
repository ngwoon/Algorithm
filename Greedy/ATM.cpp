#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	vector<int> wait;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		wait.push_back(temp);
	}

	sort(wait.begin(), wait.end());

	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			sum += wait[j];

	cout << sum;

	return 0;
}