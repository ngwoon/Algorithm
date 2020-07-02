#include <bits/stdc++.h>
using namespace std;

/*
    2580번 - 스도쿠

    백트래킹 개념에 집중해서 풀다보니 너무 생각할 조건이 많아지고, 이 때문에 시간초과가 났던 문제
    빈 장소에 숫자를 기입할 때, 행, 열, 3x3 영역을 고려해야 한다.
    만약 숫자를 넣을 때마다 들어갈 수 있는 숫자인지 브루트하게 확인한다면 시간초과가 날 수밖에 없다.
    이 대신에, 처음 스도쿠를 입력받을 때 각 행, 열, 3x3 박스에 어떤 숫자가 이미 존재하고 있는지를 체크해 준다면,
    dfs 함수에서 일일이 확인해줄 필요 없이 true,false만 확인해 주면 되므로 시간을 단축할 수 있다.

    아울러 스페셜 저지 문제이므로 답을 찾으면 바로 출력하고 exit 하면 된다.
*/

int sudoku[9][9];
bool col[9][10];
bool row[9][10];
bool box[9][10];

int toBoxIndex(int y, int x) {
    return (y/3) * 3 + x/3;
}

void dfs(int cnt) {
    if(cnt == 81) {
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) printf("%d ", sudoku[i][j]);
            printf("\n");
        }
        exit(0);
    }

    int y = cnt / 9, x = cnt % 9;
    int boxIndex = toBoxIndex(y, x);

    if(sudoku[y][x] != 0) dfs(cnt + 1);

    else {
        for(int i=1; i<=9; ++i) {
            if(!col[x][i] && !row[y][i] && !box[boxIndex][i]) {
                col[x][i]=true; row[y][i]=true; box[boxIndex][i]=true;
                sudoku[y][x]=i;
                dfs(cnt + 1);
                sudoku[y][x]=0;
                col[x][i]=false; row[y][i]=false; box[boxIndex][i]=false;
            }
        }    
    }
}

int main(void) {
    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            scanf(" %d", &sudoku[i][j]);
            
            int temp = sudoku[i][j];
            col[j][temp]=true;
            row[i][temp]=true;
            box[toBoxIndex(i,j)][temp]=true;
        }
    }

    dfs(0);
}