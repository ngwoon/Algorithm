#include <iostream>
#include <string>

using namespace std;

/*
    정렬 공부

    모든 정렬은 내림차순 기준으로 진행
*/


/* 
    선택 정렬 (Selection Sort)

    인덱스 0부터 시작
    현재 인덱스보다 큰 인덱스들을 검사 -> 가장 큰 값을 선택하여 현재 인덱스와 swap
    마지막 - 1 인덱스까지 위 과정 반복

    시간복잡도 : O(N^2)
*/

// string num;

// int main(void) {
//     cin >> num;

//     int len = num.length();
//     for(int i=0; i<len - 1; i++) {

//         int maxVal = num[i]-'0';
//         int maxIndex = i;
//         for(int j=i + 1; j<len; j++) {
//             int comp = num[j]-'0';
//             if(maxVal < comp) {
//                 maxVal = comp;
//                 maxIndex = j;
//             }
//         }

//         char temp = num[i];
//         num[i] = num[maxIndex];
//         num[maxIndex] = temp;
//     }

//     cout << num << endl;

//     return 0;
// }



/*
    삽입 정렬 (Insertion Sort)

    인덱스 1부터 시작
    현재 인덱스보다 작은 인덱스들을 검사 -> 현재 인덱스 값보다 큰 값을 만나면 탐색 종료. 해당 인덱스 + 1의 자리에 insert
    마지막 인덱스까지 위 과정 반복

    시간복잡도 : O(N^2)
*/

// string num;

// int main(void) {
//     cin >> num;

//     int len = num.length();

//     for(int i=1; i<len; i++) {
//         char cur = num[i];
//         int index = i;
//         for(int j=i - 1; j>=0; j--) {
//             if(num[j]-'0' >= cur-'0')
//                 break;
//             else
//                 index = j;
//         }

//         num.insert(num.begin() + index, cur);
//         num.erase(num.begin() + i + 1);

//         cout << num << endl << endl;
//     }

//     cout << num << endl;
// }


/* 
    버블 정렬 (Bubble Sort)

    인덱스 0부터 시작
    현재 인덱스를 i라 했을 때, i와 i+1을 검사하여 큰 값이 앞으로 오게 배치
    위 과정을 전체적으로 1번 반복했을 때, 배열 내 가장 작은 값이 맨 뒤에 가있음
    위 과정을 반복하면 뒤에서부터 오름차순 느낌으로 정렬됨

    시간복잡도 : O(N^2)
*/

// string num;

// int main(void) {
//     cin >> num;

//     int len = num.length();

//     for(int i=0; i<len - 1; i++) {
//         for(int j=1; j<len - i; j++) {
//             if(num[j-1]-'0' < num[j]-'0') {
//                 char temp = num[j-1];
//                 num[j-1] = num[j];
//                 num[j] = temp;
//             }
//         }
//     }

//     cout << num << endl;
// }



/*
    합병 정렬 (Merge Sort)

    1. 배열을 크기가 0 또는 1이 될 때까지 나눔
    2. 나뉜 배열을 두 개씩 짝지어 서로 비교하여 새로운 배열에 정렬하며 병합해나감

    1번 과정은 O(logN)
    2번 과정은 O(N)

    따라서 이 알고리즘의 시간복잡도는 O(NlogN)

    mergeSort(s1, e1);
    mergeSort(s2, e2);
    merge(s1, e1, s2, e2); 순서!!!
*/

// string num;

// void merge(int start, int mid, int end) {
//     string ret;

//     int s1 = start;
//     int e1 = mid;
//     int s2 = mid + 1;
//     int e2 = end;

//     while(s1 <= e1 && s2 <= e2) {
//         ret += (num[s1]-'0' >= num[s2]-'0' ? num[s1] : num[s2]);
//         if(ret[ret.length() - 1] == num[s1])
//             ++s1;
//         else
//             ++s2;
//     }

//     if(s1 <= e1) {
//         while(s1 <= e1)
//             ret += num[s1++];
//     } else if(s2 <= e2) {
//         while(s2 <= e2)
//             ret += num[s2++];
//     }

//     int j=0;
//     for(int i=start; i<=end; i++)
//         num[i] = ret[j++];
// }

// void mergeSort(int start, int end) {
//     if(start >= end)
//         return;

//     int mid = (start + end) / 2;

//     mergeSort(start, mid);
//     mergeSort(mid + 1, end);

//     merge(start, mid, end);
// }

// int main(void) {
//     cin >> num;

//     int len = num.length();
    
//     mergeSort(0, len-1);

//     cout << num << endl;
// }



/*
    퀵 정렬 (Quick Sort)

    pivot 사용
    pivot 설정은 개발자의 몫 (가장 왼쪽, 가장 오른쪽, 중간, 랜덤 등)
    여기선 초기 pivot을 맨 왼쪽으로 두고 시작

    left, right을 설정하여 left는 증가, right는 감소시키며 두 값을 비교
    내림차순으로 정렬하므로, arr[left] < arr[right] 일 때 두 값을 swap
    left > right가 될 때까지 반복

    이후 arr[pivot]과 arr[left]를 swap
    이러면 pivot을 기준으로 왼쪽은 pivot보다 큰 값, 오른쪽은 pivot보다 작은 값이 모여있게 된다.
    두 부류로 나누어 나뉘어진 배열 길이가 0 또는 1이 될 때까지 반복한다.

    퀵 정렬은 분할과 정복을 동시에 진행한다.

    worst case : 배열이 이미 정렬되어 있을 경우
    시간복잡도 : O(NlogN) ~ O(N^2)

    일반적으로 타 정렬보다 훨씬 빠른 속도를 갖는다.
*/ 


string num;

void quickSort(int left, int right) {

    if(left >= right)
        return;

    int tleft = left;
    int pivot = left;
    ++left;

    while(left <= right) {
        if(num[pivot]-'0' < num[left]-'0') {
            num.insert(num.begin() + pivot, num[left]);
            num.erase(num.begin() + left + 1);
            ++pivot;
        }
        ++left;
    }

    quickSort(tleft, pivot - 1);
    quickSort(pivot + 1, right);
}

int main(void) {
    cin >> num;

    quickSort(0, num.length() - 1);

    cout << num << endl;
}