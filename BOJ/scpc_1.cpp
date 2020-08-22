#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

long long ans;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
	    int n, k;
	    cin >> n >> k;
	    
	    vector<int> acal(n);
	    vector<int> bcal(n);
	    
	    for(int i=0; i<n; ++i)
	        cin >> acal[i];
	    for(int i=0; i<n; ++i)
	        cin >> bcal[i];
	    
	    sort(acal.begin(), acal.end());
	    sort(bcal.begin(), bcal.end());
	    
        ans = 0;
	    for(int i=k-1; i>=0; --i) {
	        long long cal = acal[i] + bcal[k-i-1];
	        ans = max(ans, cal);
	    }
	    
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << ans << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}