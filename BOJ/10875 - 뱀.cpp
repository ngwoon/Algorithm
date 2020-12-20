#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct line {
    int y1, x1, y2, x2;
    int dir; // 0 = 가로, 1 = 세로
    line(int a, int b, int c, int d) : y1(a), x1(b), y2(c), x2(d) {
        dir = a == c ? 0 : 1;
        if((dir == 0 && x1 < x2) || (dir == 1 && y1 < y2)) {
            x1 ^= x2; x2 ^= x1; x1 ^= x2;
            y1 ^= y2; y2 ^= y1; y1 ^= y2;
        }
    }
    line() {}
    
    void setLine(int a, int b, int c, int d) {
        y1 = a; x1 = b; y2 = c; x2 = d;
        dir = a == c ? 0 : 1;
        if((dir == 0 && x1 < x2) || (dir == 1 && y1 < y2)) {
            x1 ^= x2; x2 ^= x1; x1 ^= x2;
            y1 ^= y2; y2 ^= y1; y1 ^= y2;
        }
    }
    void setDir(int dir) {
        this->dir = dir;
    }
};

struct line leftLine;
struct line rightLine;
struct line upperLine;
struct line bottomLine;

queue<pair<int, int>> dirInfo;
vector<struct line> lines;
int L,n;

void goNext(int& y, int &x, int& dir, long long& time) {
    int gap = dirInfo.front().first;
    struct line newLine(y, x, y + gap*dy[dir], x + gap*dx[dir]);
    lines.push_back(newLine);

    y += gap*dy[dir]; x += gap*dx[dir];
    time += gap;
    dir += dirInfo.front().second;
    dirInfo.pop();

    if(dir < 0) dir = 3;
    else if(dir > 3) dir = 0;
}

void move() {
    int y=0, x=0, dir=1;
    long long time=0;

    lines.push_back(leftLine);
    lines.push_back(rightLine);
    lines.push_back(upperLine);
    lines.push_back(bottomLine);
    
    struct line origin(0,0,0,0);
    origin.setDir(1);
    lines.push_back(origin);
    origin.setDir(0);
    lines.push_back(origin);

    while(1) {
        switch(dir) {
            case 0 : {
                struct line nearLine = upperLine;
                for(int i=0; i<lines.size(); ++i) {
                    if(lines[i].dir == 0 && (lines[i].y1 < y && lines[i].x1 >= x && lines[i].x2 <= x) && lines[i].y1 > nearLine.y1)
                        nearLine = lines[i];
                }
                if(dirInfo.empty() || y - nearLine.y1 <= dirInfo.front().first) {
                    time += (y - nearLine.y1);
                    goto END;
                } else 
                    goNext(y, x, dir, time);
                
                break;
            }
            case 1 : {
                struct line nearLine = rightLine;
                for(int i=0; i<lines.size(); ++i) {
                    if(lines[i].dir == 1 && (lines[i].x1 > x && lines[i].y1 >= y && lines[i].y2 <= y) && lines[i].x1 < nearLine.x1)
                        nearLine = lines[i];
                }
                if(dirInfo.empty() || nearLine.x1 - x <= dirInfo.front().first) {
                    time += (nearLine.x1 - x);
                    goto END;
                } else 
                    goNext(y, x, dir, time);
                
                break;
            }
            case 2 : {
                struct line nearLine = bottomLine;
                for(int i=0; i<lines.size(); ++i) {
                    if(lines[i].dir == 0 && (lines[i].y1 > y && lines[i].x1 >= x && lines[i].x2 <= x) && lines[i].y1 < nearLine.y1)
                        nearLine = lines[i];
                }
                if(dirInfo.empty() || nearLine.y1 - y <= dirInfo.front().first) {
                    time += (nearLine.y1 - y);
                    goto END;
                } else 
                    goNext(y, x, dir, time);
        
                break;
            }
            case 3 : {
                struct line nearLine = leftLine;
                for(int i=0; i<lines.size(); ++i) {
                    if(lines[i].dir == 1 && (lines[i].x1 < x && lines[i].y1 >= y && lines[i].y2 <= y) && lines[i].x1 > nearLine.x1)
                        nearLine = lines[i];
                }
                if(dirInfo.empty() || x - nearLine.x1 <= dirInfo.front().first) {
                    time += (x - nearLine.x1);
                    goto END;
                } else
                    goNext(y, x, dir, time);
                
                break;
            }
            
        }
    }
END:
    printf("%lld", time);
}

int main(void) {
    scanf("%d %d", &L, &n);
    
    for(int i=0; i<n; ++i) {
        int t; char dir;
        scanf(" %d %c", &t, &dir);

        if(dir == 'L')
            dirInfo.push({t, -1});
        else
            dirInfo.push({t, 1});
    }

    leftLine.setLine(-L-1, -L-1, L+1, -L-1);
    rightLine.setLine(-L-1, L+1, L+1, L+1);
    upperLine.setLine(-L-1, -L-1, -L-1, L+1);
    bottomLine.setLine(L+1, -L-1, L+1, L+1);

    move();

    return 0;
}