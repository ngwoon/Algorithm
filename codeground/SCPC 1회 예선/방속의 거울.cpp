#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

char room[1000][1000];
bool visited[1000][1000];
int n;
// dir : 북 동 남 서 (0 1 2 3)
int simul() {
    int y=0, x=0;
    int dir=1, cnt=0;
    while(1) {
        while(y >= 0 && y < n && x >= 0 && x < n && room[y][x] == '0') {
            y += dy[dir]; x += dx[dir];
        }

        if(y < 0 || y >= n || x < 0 || x >= n)
            break;

        // 거울 만났을 때
        if(!visited[y][x]) {
            visited[y][x] = true;
            ++cnt;
        }
        if(room[y][x] == '1') {
            switch(dir) {
                case 0 : dir = 1; break;
                case 1 : dir = 0; break;
                case 2 : dir = 3; break;
                case 3 : dir = 2; break; 
            }
        } else {
            switch(dir) {
                case 0 : dir = 3; break;
                case 1 : dir = 2; break;
                case 2 : dir = 1; break;
                case 3 : dir = 0; break;
            }
        }
        y += dy[dir]; x += dx[dir];
    }
    return cnt;
}

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
        scanf("%d", &n);
		
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j)
                scanf(" %c", &room[i][j]);
        }

        for(int i=0; i<n; ++i)
            memset(visited[i], false, n);

        printf("Case #%d\n", test_case+1);
        printf("%d\n", simul());
	}

	return 0;//Your program should return 0 on normal termination.
}