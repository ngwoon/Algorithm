#include <bits/stdc++.h>
using namespace std;

int field[8][8];
int sum[8][8];
int row[8], exRow[8];
int col[8], exCol[8];
int sprayer[8][8];
int m,k;

int main(void) {
    scanf("%d %d", &m, &k);
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            scanf("%d", &field[i][j]);
            row[i] += field[i][j];
            col[j] += field[i][j];
        }
    }

    memset(sprayer, '.', sizeof(sprayer));
    fill(exRow, exRow + 8, m);
    fill(exCol, exCol + 8, m);

    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            sum[i][j] = row[i] + col[j] - field[i][j]; 
            if(sum[i][j] % 2 == 1) {
                sprayer[i][j] = '*';
                ++exRow[i]; ++exCol[j];
            }
        }
    }

    int newMap[8][8] = {0};
    int newR[8], newC[8];
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            if(sprayer[i][j] == '*') {
                newMap[i][j] = exRow[i] + exCol[j] - 1;
                newR[i] += newMap[i][j];
                newC[j] += newMap[i][j];
            }
        }
    }

    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            if(sprayer[i][j] == '*') {
                int newSum = newR[i] + newC[j] - newMap[i][j];
                if((newSum - sum[i][j]) % 4 == 0)
                    sprayer[i][j] = '+';
                else
                    sprayer[i][j] = '-';
            }
        }
    }

    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j)
            printf("%c ", sprayer[i][j]);
        printf("\n");
    }
}