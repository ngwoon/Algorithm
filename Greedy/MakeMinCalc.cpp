#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> operands;
	vector<char> optr;
	string line;

	cin >> line;

	char buf[6];
	int index = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '+' || line[i] == '-') {
			buf[index] = '\0';
			operands.push_back(stoi(buf));
			optr.push_back(line[i]);
			
			//buf 내용 NULL로 초기화
			for (int j = 0; j < 6; j++)
				buf[j] = '\0';
			
			index = 0;
		}
		else
			buf[index++] = line[i];
	}

	//마지막 수 추가
	operands.push_back(stoi(buf));

	/*for (int i = 0; i < operands.size(); i++)
		cout << operands[i] << endl;*/
	
	for (int i = 0; i < optr.size(); i++) {
		if (optr[i] == '+') {
			int sum = operands[i] + operands[i + 1];
			operands[i] = sum;
			operands.erase(operands.begin() + (i + 1));
			optr.erase(optr.begin() + i);
			--i;
		}
	}

	int result = operands[0];
	for (int i = 1; i < operands.size(); i++)
		result -= operands[i];

	cout << result;

	return 0;
}