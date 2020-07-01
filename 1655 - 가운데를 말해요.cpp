// #include <bits/stdc++.h>
// using namespace std;

// int heap[100001];
// int lastIndex;
// string ans;


// int main(void) {
//     int n;
//     scanf("%d", &n);
//     heap[0] = 1000001;
//     while(n--) {
//         int num;
//         scanf("%d", &num);

//         // push
//         heap[++lastIndex] = num;

//         int child = lastIndex;
//         int parent = child / 2;
//         while(parent >= 1 && heap[child] < heap[parent]) {
//             heap[child] ^= heap[parent];
//             heap[parent] ^= heap[child];
//             heap[child] ^= heap[parent];
//             child = parent;
//             parent = child / 2;
//         }

//         printf("======================\n");
//         for(int i=1; i<=lastIndex; ++i)
//             printf("%d ", heap[i]);
//         printf("\n");

//         if(lastIndex % 2 == 1)
//             ans.append(to_string(heap[lastIndex/2 + 1]) + "\n");
//         else
//             ans.append(to_string(heap[lastIndex/2]) + "\n");
//     }

//     printf("%s", ans.c_str());
// }



#include <bits/stdc++.h>
using namespace std;

/*
    1655 - 가운데를 말해요

    수를 추가할 때 마다 현재 리스트의 중간 인덱스 값을 출력하는 문제.

    수를 삽입할 때 오름차순으로 정렬된 상태를 유지하는 방향으로 삽입하여 풀었다.

    lower_bound를 사용하여 이분탐색으로 탐색 시간을 줄였지만, 약 800ms로 시간복잡도가 꽤 큰 결과가 나왔다.
    
    개선 방법을 생각할 필요가 있는 코드.
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
