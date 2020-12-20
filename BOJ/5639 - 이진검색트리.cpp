#include <bits/stdc++.h>
using namespace std;

/*
    백준 5639번 - 이진 검색 트리

    말 그대로 트리 삽입 형식으로 구현하면 되는 문제

    다른 사람이 푼 코드에서 굉장히 간결하고 독특하게 푼 것을 보았는데
    트리 배열을 반으로 나누면 왼쪽 서브 트리, 오른쪽 서브 트리가 되는 것을 응용하여
    트리 재구성과 postorder를 한번에 하는 방식이었다.

    아래 주석으로 해당 코드를 옮겨놓았다.
*/

typedef struct node {
    node(int key) { this->key = key; }
    int key;
    struct node* left=NULL;
    struct node* right=NULL;
}NODE;

vector<int> nums;
NODE* root;
int cnt=0;

void postOrder(NODE* cur) {
    if(cur->left != NULL) postOrder(cur->left);
    if(cur->right!= NULL) postOrder(cur->right);
    cout << cur->key << "\n";
}

void insert(int key) {
    
    NODE* newNode = new NODE(key);
    // 루트 노드 삽입
    if(cnt == 0) {
        root = newNode;
        ++cnt;
        return;
    }

    NODE* temp=root;
    while(1) {
        // 왼쪽 자식으로 삽입될 때
        if(temp->key > key) {
            if(temp->left != NULL) {
                temp = temp->left;
                continue;
            } else {
                temp->left = newNode;
                break;
            }
        } else if(temp->key < key) {
            if(temp->right != NULL) {
                temp = temp->right;
                continue;
            } else {
                temp->right = newNode;
                break;
            }
        }
    }
    ++cnt;
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int num;
    while(cin >> num)
        nums.push_back(num);

    for(int i=0; i<nums.size(); ++i)
        insert(nums[i]);

    postOrder(root);
}





#include <iostream>
#include <algorithm>
using namespace std;
int Arr[10002];
 
void printNode(const int& left, const int& right) {
    if (left > right) return;
    
    int root = Arr[left];
    int last = right;
    while (Arr[last] > root) last--;
    //Arr[left]를 부모 노드로 하고 두 가지로 나뉜다.
    //왼쪽 노드가 되고
    printNode(left + 1, last);
    //오른쪽 노드가 된다.
    printNode(last + 1, right);
    //자신은 출력해주자.
    printf("%d\n", root);
}
 
int main() {
    int temp;
    int N = 0;
    while (scanf("%d", &temp) != -1) Arr[N++] = temp;
    printNode(0, N-1);
 
    return 0;
}

