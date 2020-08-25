#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535

int a,b,c,d,e;

double getDegree(double y, double x){
   return atan2(y,x) * 180 / PI;
}

int getScore(int x, int y, map<pair<int, int>, int>& dart) {

    double len = sqrt(x*x + y*y);

    int score;
    if(len < a) 
        score = 50;
    else if(len > e)
        score = 0;
    else {
        double deg = getDegree(y, x);
        if(deg < 0) deg += 360;

        for(auto it=dart.begin(); it!=dart.end(); ++it) {
            int left = it->first.first, right = it->first.second;
            if(left > right) {
                if(deg > left || deg < right) {
                    score = it->second;
                    break;
                }
            } else {
                if(left < deg && deg < right) {
                    score = it->second;
                    break;
                }
            }
        }

        if(len > b && len < c)
            score *= 3;
        else if(len > d && len < e)
            score *= 2;
    }

    return score;
}

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

    map<pair<int, int>, int> dart;

    dart.insert({{9, 27}, 13});
    dart.insert({{27, 45}, 4});
    dart.insert({{45, 63}, 18});
    dart.insert({{63, 81}, 1});
    dart.insert({{81, 99}, 20});
    dart.insert({{99, 117}, 5});
    dart.insert({{117, 135}, 12});
    dart.insert({{135, 153}, 9});
    dart.insert({{153, 171}, 14});
    dart.insert({{171, 189}, 11});
    dart.insert({{189, 207}, 8});
    dart.insert({{207, 225}, 16});
    dart.insert({{225, 243}, 7});
    dart.insert({{243, 261}, 19});
    dart.insert({{261, 279}, 3});
    dart.insert({{279, 297}, 17});
    dart.insert({{297, 315}, 2});
    dart.insert({{315, 333}, 15});
    dart.insert({{333, 351}, 10});
    dart.insert({{351, 9}, 6});

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        
        int n;
        scanf("%d", &n);

        int score = 0;
        for(int i=0; i<n; ++i) {
            int x,y;
            scanf("%d %d", &x, &y);
            score += getScore(x,y, dart);
        }

		printf("Case #%d\n", test_case+1);
        printf("%d\n", score);;
	}

	return 0;//Your program should return 0 on normal termination.
}