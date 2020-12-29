#include <bits/stdc++.h>
using namespace std;

vector<char> gears[4];
int flag;

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<4; ++i) {
        gears[i].resize(8);
        char gear[9];
        scanf("%s ", gear);
        for(int j=0; j<8; ++j)
            gears[i][j] = gear[j];
    }

    int m;
    scanf("%d", &m);

    for(int i=0; i<m; ++i) {
        int num, dir;
        scanf("%d %d", &num, &dir);

        num -= 1;

        vector<int> change(4);
        change[num] = dir;
        int preDir = dir;
        for(int j=num-1; j>=0; --j) {
            if(preDir == 0) {
                change[j] = 0;
                continue;
            }

            if(gears[j][2] != gears[j+1][6])
                change[j] = preDir == 1 ? -1 : 1;
            else
                change[j] = 0;
            
            preDir = change[j];
        }

        preDir = dir;
        for(int j=num+1; j<4; ++j) {
            if(preDir == 0) {
                change[j] = 0;
                continue;
            }
            
            if(gears[j][6] != gears[j-1][2])
                change[j] = preDir == 1 ? -1 : 1;
            else
                change[j] = 0;

            preDir = change[j];
        }

        for(int j=0; j<4; ++j) {
            if(change[j] == 1)
                rotate(gears[j].begin(), gears[j].begin() + gears[j].size() - 1, gears[j].end());
            else if(change[j] == -1)
                rotate(gears[j].begin(), gears[j].begin() + 1, gears[j].end());
        }

        // printf("i = %d\n", i);
        // for(int j=0; j<4; ++j) {
        //     for(int k=0; k<8; ++k) {
        //         printf("%c ", gears[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }

    int ans=0;
    for(int i=0; i<4; ++i) {
        if(gears[i][0] == '1')
            ans += pow(2, i);
    }

    printf("%d", ans);
}