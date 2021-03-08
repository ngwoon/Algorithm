// #include <bits/stdc++.h>
// using namespace std;

// priority_queue<int, vector<int>, greater<int>> pq;

// int main(void) {
//     int x;
//     scanf("%d", &x);

//     pq.push(64);
//     int sum=64;
//     int cnt=1;

//     while(sum != x) {
//         int shortest = pq.top();
//         pq.pop();
//         sum -= shortest;
//         cnt -= 1;

//         int half = shortest / 2;
//         sum += half;
//         cnt += 1;

//         if(sum >= x)
//             pq.push(half);
//         else {
//             sum += half;
//             pq.push(half);
//             pq.push(half);
//             cnt += 1;
//         }
//     }

//     printf("%d", cnt);
// }

#include <bits/stdc++.h>
using namespace std;

stack<int> stick;
int len;
int X;

int main(void) {
    cin >> X;

    stick.push(64);
    len=64;
    while(1) {
        if(len == X) { cout << stick.size(); break; }

        int cur = stick.top();
        stick.pop();
        len-=cur;

        int div = cur/2;

        if(div == 0) continue;

        stick.push(div);
        int curlen = len + div;

        if(curlen < X) { 
            len = curlen + div; 
            stick.push(div); 
        } else if(curlen >= X) 
            len = curlen; 
    }
}