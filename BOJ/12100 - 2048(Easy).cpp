#include <bits/stdc++.h>
using namespace std;

int n;

int play(vector<vector<int>> board, int depth) {    

    if(depth == 5) {
        int maxVal = 2;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(maxVal < board[i][j])
                    maxVal = board[i][j];
            }
        }
        return maxVal;
    }

    // 좌
    vector<vector<int>> tempBoard(n);
    copy(board.begin(), board.end(), tempBoard.begin());

    int maxVal = 2;
    for(int i=0; i<n; ++i) {
        int mvIdx = 0;
        for(int j=0; j<n; ++j) {
            if(tempBoard[i][j] == 0)
                continue;
            
            int nearNum = 0;
            int nearIdx = n;
            bool isComBined = false;
            for(int k=j+1; k<n; ++k) {
                if(tempBoard[i][k] == 0)
                    continue;
                nearNum = tempBoard[i][k];
                nearIdx = k;
                break;
            }

            if(tempBoard[i][j] == nearNum) {
                tempBoard[i][j] *= 2;
                tempBoard[i][nearIdx] = 0;
                j = nearIdx;
            } else {
                j = nearIdx - 1;
            }
        }
    }
    for(int i=0; i<n; ++i) {
        int mvIdx = 0;
        for(int j=0; j<n; ++j) {
            if(tempBoard[i][j] == 0)
                continue;
            if(mvIdx == j) {
                ++mvIdx;
            } else {
                tempBoard[i][mvIdx] = tempBoard[i][j];
                tempBoard[i][j] = 0;
                ++mvIdx;
            }
        }
    }
    int result = play(tempBoard, depth+1);
    maxVal = maxVal < result ? result : maxVal;


    // 우
    copy(board.begin(), board.end(), tempBoard.begin());
    for(int i=0; i<n; ++i) {
        for(int j=n-1; j>=0; --j) {
            if(tempBoard[i][j] == 0)
                continue;
            
            int nearNum = 0;
            int nearIdx = -1;
            bool isCombined = false;
            for(int k=j-1; k>=0; --k) {
                if(tempBoard[i][k] == 0)
                    continue;
                nearNum = tempBoard[i][k];
                nearIdx = k;
                break;
            }

            if(tempBoard[i][j] == nearNum) {
                tempBoard[i][j] *= 2;
                tempBoard[i][nearIdx] = 0;
                j = nearIdx;
            } else {
                j = nearIdx + 1;
            }
        }
    }
    for(int i=0; i<n; ++i) {
        int mvIdx = n-1;
        for(int j=n-1; j>=0; --j) {
            if(tempBoard[i][j] == 0)
                continue;
            if(mvIdx == j) {
                --mvIdx;
            } else {
                tempBoard[i][mvIdx] = tempBoard[i][j];
                tempBoard[i][j] = 0;
                --mvIdx;
            }
        }
    }
    result = play(tempBoard, depth+1);
    maxVal = maxVal < result ? result : maxVal;


    // 상
    copy(board.begin(), board.end(), tempBoard.begin());
    for(int j=0; j<n; ++j) {
        for(int i=0; i<n; ++i) {
            if(tempBoard[i][j] == 0)
                continue;
            
            int nearNum = 0;
            int nearIdx = n;
            bool isCombined = false;
            for(int k=i+1; k<n; ++k) {
                if(tempBoard[k][j] == 0)
                    continue;
                nearNum = tempBoard[k][j];
                nearIdx = k;
                break;
            }

            if(tempBoard[i][j] == nearNum) {
                tempBoard[i][j] *= 2;
                tempBoard[nearIdx][j] = 0;
                i = nearIdx;
            } else {
                i = nearIdx - 1;
            }
        }
    }
    for(int j=0; j<n; ++j) {
        int mvIdx = 0;
        for(int i=0; i<n; ++i) {
            if(tempBoard[i][j] == 0)
                continue;
            if(mvIdx == i) {
                ++mvIdx;
            } else {
                tempBoard[mvIdx][j] = tempBoard[i][j];
                tempBoard[i][j] = 0;
                ++mvIdx;
            }
        }
    }
    result = play(tempBoard, depth+1);
    maxVal = maxVal < result ? result : maxVal;


    // 하
    copy(board.begin(), board.end(), tempBoard.begin());
    for(int j=0; j<n; ++j) {
        for(int i=n-1; i>=0; --i) {
            if(tempBoard[i][j] == 0)
                continue;
            
            int nearNum = 0;
            int nearIdx = -1;
            bool isCombined = false;
            for(int k=i-1; k>=0; --k) {
                if(tempBoard[k][j] == 0)
                    continue;
                nearNum = tempBoard[k][j];
                nearIdx = k;
                break;
            }

            if(tempBoard[i][j] == nearNum) {
                tempBoard[i][j] *= 2;
                tempBoard[nearIdx][j] = 0;
                i = nearIdx;
            } else {
                i = nearIdx + 1;
            }
        }
    }
    for(int j=0; j<n; ++j) {
        int mvIdx = n-1;
        for(int i=n-1; i>=0; --i) {
            if(tempBoard[i][j] == 0)
                continue;
            if(mvIdx == i) {
                --mvIdx;
            } else {
                tempBoard[mvIdx][j] = tempBoard[i][j];
                tempBoard[i][j] = 0;
                --mvIdx;
            }
        }
    }
    result = play(tempBoard, depth+1);
    maxVal = maxVal < result ? result : maxVal;

    return maxVal;
}

int main(void) {
    scanf("%d", &n);

    vector<vector<int>> board;
    board.resize(n);
    for(int i=0; i<n; ++i)
        board[i].resize(n);
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j)
            scanf("%d", &board[i][j]);
    }

    printf("%d", play(board, 0));
}