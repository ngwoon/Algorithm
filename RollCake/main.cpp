#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int expted[1001];
int result[1001];
int cake[1001];

int main(void)
{
	int len, crowd;

	cin >> len >> crowd;

	memset(cake, 0, (len + 1));

	int start, end;
	int cnt = 0, cntMax = 0;
	for (int i = 1; i < crowd + 1; i++)
	{
		cin >> start >> end;

		expted[i] = end - start;

		for (int j = start; j <= end; j++)
		{
			if (cake[j] != 0)
			{
				if (cntMax < cnt)
					cntMax = cnt;
				cnt = 0;
				continue;
			}
			else
			{
				cake[j] = i;
				cnt++;
			}
		}
		if (cntMax < cnt)
			cntMax = cnt;

		result[i] = cntMax;

		cntMax = 0;
		cnt = 0;
	}


	// "emax" and "rmax" each is a variable that stores max value in expted,
	// "ep" and "rp" each is a variable that stores index correspond with em
	int emax = 0, rmax = 0;
	int ep = 0, rp = 0;
	for (int i = 1; i < crowd + 1; i++)
	{
		if (emax < expted[i])
		{
			emax = expted[i];
			ep = i;
		}
		if (rmax < result[i])
		{
			rmax = result[i];
			rp = i;
		}
	}
	cout << "expted arr" << endl;
	for (int i = 1; i < crowd + 1; i++)
		cout << expted[i] << " ";
	cout << endl;

	cout << "result arr" << endl;
	for (int i = 1; i < crowd + 1; i++)
		cout << result[i] << " ";
	cout << endl;

	cout << "cake arr" << endl;
	for (int i = 1; i < len + 1; i++)
		cout << cake[i] << " ";
	cout << endl;

	cout << ep << "\n" << rp;

	system("pause");
}
