#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

typedef struct fireball {
    int r,c,m,s,d;
}FIREBALL;

vector<FIREBALL> field[50][50];
int n,m,k;

void order() {
    while(k--) {
        // 이동
        queue<FIREBALL> que;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                while(!field[i][j].empty()) {
                    FIREBALL cur = field[i][j].back();
                    field[i][j].pop_back();

                    cur.r += (dy[cur.d] * cur.s) % n;
                    cur.c += (dx[cur.d] * cur.s) % n;

                    if(cur.r < 0)
                        cur.r += n;
                    if(cur.r >= n)
                        cur.r -= n;
                    if(cur.c < 0)
                        cur.c += n;
                    if(cur.c >= n)
                        cur.c -= n;

                    que.push(cur);
                }
            }
        }

        while(!que.empty()) {
            FIREBALL temp = que.front();
            que.pop();
            field[temp.r][temp.c].push_back(temp);
        }

        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                int vsize = field[i][j].size();
                if(vsize >= 2) {
                    int msum = 0, ssum = 0;
                    vector<int> ds;
                    while(!field[i][j].empty()) {
                        FIREBALL back = field[i][j].back();
                        field[i][j].pop_back();
                        msum += back.m;
                        ssum += back.s;
                        ds.push_back(back.d);
                    }

                    int isSameD = field[i][j][0].d % 2 == 0 ? 0 : 1;
                    for(int k=0; k<vsize; ++k) {
                        if(isSameD == 1 && ds[k] % 2 == 0)
                            isSameD = -1;
                        else if(isSameD == 0 && ds[k] % 2 == 1)
                            isSameD = -1;
                    }

                    int nm = msum / 5;
                    int ns = ssum / vsize;
                    if(nm == 0)
                        continue;
                    for(int k=0; k<4; ++k)
                        field[i][j].push_back({i, j, nm, ns, isSameD == -1 ? k*2+1 : k*2});
                }
            }
        }
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<m; ++i) {
        int r, c, mm, s, d;
        scanf("%d %d %d %d %d", &r, &c, &mm, &s, &d);
        FIREBALL fireball = {r-1,c-1,mm,s,d};
        field[r-1][c-1].push_back(fireball);
    }

    order();

    int ans=0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            for(int k=0; k<field[i][j].size(); ++k)
                ans += field[i][j][k].m;
        }
    }

    printf("%d", ans);
}