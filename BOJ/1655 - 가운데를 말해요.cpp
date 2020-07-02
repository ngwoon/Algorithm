#include <bits/stdc++.h>
using namespace std;

/*
    1655 - 가운데를 말해요

    수를 추가할 때 마다 현재 리스트의 중간 인덱스 값을 출력하는 문제.

    수를 삽입할 때 오름차순으로 정렬된 상태를 유지하는 방향으로 삽입하여 풀었다.

    lower_bound를 사용하여 이분탐색으로 탐색 시간을 줄였지만, 약 800ms로 시간복잡도가 꽤 큰 결과가 나왔다.
    
    
    2020-07-02 개선한 코드
    중간값을 찾아내는 과정을 줄이기 위해, 입력받는 수를 bq, sq에 나누어 담는다.
    bq, sq는 우선순위 큐이며, bq는 작은 수가 높은 우선순위를, sq는 높은 수가 높은 우선순위를 갖게 하여
    수 입력을 받았을 때 bq.top과 sq.top으로 중간값을 비교할 수 있도록 한다.

    아울러 bq와 sq의 요소 개수 차가 1을 넘지 않도록 조정해주어 항상 sq.top이 중간값이 될 수 있도록 한다.
*/

vector<int> nums;
string ans;

int main(void) {
    int n;
    scanf("%d", &n);
    while(n--) {
        int num;
        scanf(" %d", &num);

        vector<int>::iterator iter = lower_bound(nums.begin(), nums.end(), num);
        if(iter == nums.end()) nums.push_back(num);
        else nums.insert(iter, num);

        ans.append(to_string(nums[(nums.size()-1) / 2]) + "\n");
    }
    printf("%s", ans.c_str());
}

// #include <bits/stdc++.h>
// using namespace std;

// priority_queue<int, vector<int>, greater<int>> bq;
// priority_queue<int, vector<int>> sq;
// string ans;

// int main(void) {
//     int n;
//     scanf("%d", &n);
//     while(n--) {
//         int num;
//         scanf(" %d", &num);

//         if(sq.empty()) {
//             sq.push(num);
//             ans.append(to_string(num) + "\n");
//         } else {
//             if(sq.size() > bq.size()) {
//                 if(sq.top() <= num) {
//                     bq.push(num);
//                 } else {
//                     bq.push(sq.top());
//                     sq.pop();
//                     sq.push(num);
//                 }
//             } else {
//                 if(bq.top() > num)
//                     sq.push(num);
//                 else {
//                     sq.push(bq.top());
//                     bq.pop();
//                     bq.push(num);
//                 }
//             }
//             ans.append(to_string(sq.top()) + "\n");
//         }
//     }
//     printf("%s", ans.c_str());
// }
