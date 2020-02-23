#include <bits/stdc++.h>
using namespace std;

char orders[4] = {'D', 'S', 'L', 'R'};

queue<int> que;
bool visited[10000];
pair<int, int> route[10000] = {{0,0}};
int T;

/*
    order
    0 1 2 3 == D S L R
*/
int move(int num, int order) {
    int result=num;
    if(order == 0) result = (result << 1) % 10000;
    else if(order == 1) result = (--result < 0 ? 9999 : result);
    else {
        int each[4]; // 각 자릿수 저장 (each[0] : 일의 자리)
        int temp = num;

        int digit = 10;
        for(int i=0; i<4; i++) {
            each[i] = temp % digit;
            
            temp -= each[i];
            each[i] /= (digit/10);
            digit *= 10;
        }

        int tempEach[4];
        if(order == 2) {
            tempEach[0] = each[3];
            tempEach[1] = each[0];
            tempEach[2] = each[1];
            tempEach[3] = each[2];
        } else {
            tempEach[0] = each[1];
            tempEach[1] = each[2];
            tempEach[2] = each[3];
            tempEach[3] = each[0];
        }

        result = 0;
        digit = 1;
        for(int j=0; j<4; j++) {
            result += tempEach[j] * digit;
            digit *= 10;
        }
    }

    return result;
}

void bfs(int start, int end) {
    que.push(start);
    visited[start]=true;

    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        if(cur == end) {
            while(!que.empty())
                que.pop();
            break;
        }

        for(int i=0; i<4; i++) {
            int nc = move(cur, i);

            if(visited[nc])
                continue;

            route[nc] = {cur, i};
            visited[nc] = true;
            que.push(nc);
        }
    }
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    for(int i=0; i<T; i++) {
        int start, end;
        cin >> start >> end;
        bfs(start, end);

        stack<char> answer;
        while(end != start) {
            answer.push(orders[route[end].second]);
            end = route[end].first;
        }
        while(!answer.empty()) {
            printf("%c", answer.top());
            answer.pop();
        }
        printf("\n");

        memset(visited, false, 10001);
        for(int j=1; j<10001; j++)
            route[j] = {0, 0};
    }
}