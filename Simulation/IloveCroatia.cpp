#include <iostream>

#define LIMIT 210

using namespace std;

int main(void)
{
	int person, qust;

	cin >> person >> qust;

	int timeflow = 0;
	for (int i = 0; i < qust; i++)
	{
		int time;
		char stat;

		cin >> time >> stat;

		timeflow += time;

		if (timeflow >= LIMIT)
			break;

		if (stat == 'T')
			person = (person % 8) + 1;
	}

	cout << person;

	system("pause");

	return 0;
}