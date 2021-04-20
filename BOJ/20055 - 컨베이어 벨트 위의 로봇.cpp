#include <bits/stdc++.h>
using namespace std;

pair<bool, int> conveyor[200];
int broken, step;
int n, k;

void printConveyor() {
    for(int i=0; i<n; ++i) {
        printf("%c ", (conveyor[i].first ? 'r' : '0'));
    }
    printf("\n");

    for(int i=0; i<n; ++i) {
        printf("%d ", conveyor[i].second);
    }
    printf("\n\n");
}

int main(void) {
    scanf("%d %d", &n, &k);

    for(int i=0; i<2*n; ++i) {
        int durability;
        scanf("%d", &durability);
        conveyor[i] = {false, durability};
    }

    while(1) {
        ++step;

        // 컨베이어 벨트 움직임
        pair<bool, int> prev = conveyor[0];
        for(int i=0; i<2*n; ++i) {
            int nextIdx = (i+1) % (2*n);

            if(i == n-1 && conveyor[i].first)
                conveyor[i].first = false;
            
            pair<bool, int> temp = conveyor[nextIdx];
            conveyor[nextIdx] = prev;
            prev = temp;
        }
    
        // 로봇 움직임
        for(int i=n-2; i>=0; --i) {
            if(conveyor[i].first) {
                if(!conveyor[i+1].first && conveyor[i+1].second > 0) {
                    conveyor[i].first = false;
                    conveyor[i+1].first = true;
                    --conveyor[i+1].second;

                    if(conveyor[i+1].second == 0)
                        ++broken;
                }
            }
        }
        if(broken >= k) {
            printf("%d", step);
            break;
        }

        // 올라가는 칸에 로봇 올릴지 말지 결정
        if(!conveyor[0].first && conveyor[0].second > 0) {
            conveyor[0] = {true, conveyor[0].second - 1};
            if(conveyor[0].second == 0)
                ++broken;
        }
        
        if(broken >= k) {
            printf("%d", step);
            break;
        }
    }
}