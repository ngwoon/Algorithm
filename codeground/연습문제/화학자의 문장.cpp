#include <bits/stdc++.h>
using namespace std;

int dp[50000];
unordered_set<string> symbols;
string str;

int solve(int idx) {
    if(idx >= str.length())
        return 1;
    
    int& ret = dp[idx];
    if(ret == -1) {
        ret = 0;
        if(symbols.find(str.substr(idx, 1)) != symbols.end()) {
            ret = solve(idx+1);
        }
        if(ret == 0 && idx < str.length()-1 && symbols.find(str.substr(idx, 2)) != symbols.end()) {
            ret = solve(idx+2);
        }
    }
    
    return ret;
}

int main(void)
{
	int T, test_case;

    string temp[] = { 
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
        "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
        "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
        "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
        "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
        "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
        "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
        "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
        "No", "Lr" 
    };

    for(int i=0; i<114; ++i) {
        for(int j=0; j<temp[i].size(); ++j)
            temp[i][j] = tolower(temp[i][j]);
        symbols.insert(temp[i]);
    }

	cin >> T; cin.ignore();
	for(test_case = 0; test_case < T; test_case++)
	{
        getline(cin, str);

        memset(dp, -1, sizeof(dp));
        solve(0);

		cout << "Case #" << test_case+1 << endl;
        if(dp[0])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}