#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	vector<pair<int, int>> lectures;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;

		cin >> start >> end;

		lectures.push_back({ end, start });
	}

	sort(lectures.begin(), lectures.end());

	int cnt = 1;
	int vsize = lectures.size();
	int endpoint = lectures[0].first;
	for (int i = 1; i < vsize; i++) {
		if (endpoint <= lectures[i].second) {
			++cnt;
			endpoint = lectures[i].first;
		}
	}
	
	cout << cnt;

	return 0;
}