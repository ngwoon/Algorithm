#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

/*
    백준 1068번 - 트리

    기본적인 부모-자식 관계 정의하는 문제이지만
    입력받을 때 주의가 필요하다.

    루트 노드가 입력 순서 뒤쪽에 나왔을 경우, 루트 노드의 자식들은 아직 루트 노드와 이어지지 못한 상태다.
    따라서 입력받은 후에 루트와 그의 자식들을 연결해주는 과정이 필요하다.

    나는 트리를 그래프의 인접리스트처럼 구현했고, 추가-삭제 하는데 시간이 조금 더 걸린 듯 하다.
*/

using namespace std;

vector<int> tree[50];
int parent[50];
int N, delNode;

int dfs(int cur) {
    if(tree[cur].size() == 0) return 1;

    int sum=0;
    for(int i=0; i<tree[cur].size(); ++i)
        sum += dfs(tree[cur][i]);

    return sum;
}

bool deleteNode(int cur) {
    auto iter = find(tree[cur].begin(), tree[cur].end(), delNode);
    if(iter != tree[cur].end()) {
        tree[cur].erase(iter);
        return true;
    }
    for(int i=0; i<tree[cur].size(); ++i) {
        if(deleteNode(tree[cur][i])) return true;
    }
    return false;
}

int main(void) {
    int root;
    scanf("%d", &N);

    memset(parent, -1, sizeof(int)*N);
    for(int i=0; i<N; ++i) {
        int node;
        scanf(" %d", &node);
        if(node != -1) { tree[node].push_back(i); parent[i] = node; }
        else root = i;
    }

    for(int i=0; i<N; ++i) {
        if(i != root && parent[i] == -1) {
            parent[i] = root;
            tree[root].push_back(i);
        }
    }

    scanf(" %d", &delNode);

    if(!deleteNode(root)) { printf("0"); exit(0); }

    printf("%d", dfs(root));
}