#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits.h>

#define INF LLONG_MAX

using namespace std;

vector<pair<int, int>> adj[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
vector<int> ic; // 면접장이 있는 도시 번호
long long dst[100001];

void dijkstra()
{
	for (int i = 0; i < ic.size(); i++)
	{
		dst[ic[i]] = 0;
		pq.push({ 0, ic[i] });
	}

	while (!pq.empty())
	{
		int cn = pq.top().second; // city num
		long long ndst = pq.top().first; // now distance
		pq.pop();

		if (ndst > dst[cn])
			continue;

		for (int i = 0; i < adj[cn].size(); i++)
		{
			int adjw = adj[cn][i].first; // adj weight(cost)
			int adjc = adj[cn][i].second; // city num

			if (dst[adjc] > dst[cn] + adjw)
			{
				dst[adjc] = dst[cn] + adjw;
				pq.push({ dst[adjc] , adjc });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 1; i < M + 1; i++)
	{
		int c1, c2, cost;
		cin >> c1 >> c2 >> cost;

		adj[c2].push_back({ cost, c1 });
	}

	//면접장 있는 도시 입력
	int temp;
	for (int i = 1; i < K + 1; i++)
	{
		cin >> temp;
		ic.push_back(temp);
	}

	//INF init
	for (int j = 1; j < N + 1; j++)
		dst[j] = INF;

	dijkstra();

	/*for (int i = 1; i < N + 1; i++)
		cout << "dst[" << i << "]=" << dst[i] << endl;
	cout << endl;*/

	int maxIndex = -1;
	long long maxDst = -1;
	for (int i = 1; i < N + 1; i++)
	{
		if (maxDst < dst[i])
		{
			maxDst = dst[i];
			maxIndex = i;
		}
	}

	cout << maxIndex << endl;
	cout << maxDst;

	system("pause");

	return 0;
}