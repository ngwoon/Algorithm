#include <bits/stdc++.h>
using namespace std;

#define S(n) (((long long)(n))*((n)+1)/2)

int n, k;

long long getNum(int x, int y) {
    return ((y+x < n) ? (S(y+x+1) - (((y+x)%2) ? x : y)) : ((long long)n*n - S(2*n-y-x-2) - n + 1 + (((y+x)%2) ? y : x)));
}

int main(void)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
        cin >> n >> k;

        string mov;
        cin >> mov;

        int x = 0, y = 0;
        long long sum = 1;
        for(int i=0; i<mov.length(); ++i) {
            switch(mov[i]) {
                case 'U' : y -= 1; break;
                case 'D' : y += 1; break;
                case 'L' : x -= 1; break;
                case 'R' : x += 1; break;
            }

            sum += getNum(x,y);
        }
		cout << "Case #" << test_case+1 << endl;
        cout << sum << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}