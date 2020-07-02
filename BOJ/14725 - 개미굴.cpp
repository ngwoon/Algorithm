#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    string val;
    vector<string> childVal;
    vector<struct node*> child;
}NODE;

int N;
NODE* root = new NODE{"ROOT", *new vector<string>, *new vector<NODE*>};

void dfs(NODE* cur, int depth) {
    
    if(cur != root) {
        for(int i=0; i<depth; ++i) cout << "--";
        cout << cur->val << endl;
    }

    for(int i=0; i<cur->child.size(); ++i)
        dfs(cur->child[i], depth+1);
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i=0; i<N; ++i) {
        int temp;
        cin >> temp;

        NODE* parent=root;
        for(int j=0; j<temp; ++j) {
            string fruit;
            cin >> fruit;

            vector<string>::iterator iter = find(parent->childVal.begin(), parent->childVal.end(), fruit);
            if(iter == parent->childVal.end()) {
                int insertIndex = upper_bound(parent->childVal.begin(), parent->childVal.end(), fruit) - parent->childVal.begin();
                parent->childVal.insert(parent->childVal.begin() + insertIndex, fruit);
                NODE* newNode = new NODE{fruit, *new vector<string>, *new vector<NODE*>};
                parent->child.insert(parent->child.begin() + insertIndex, newNode);

                parent = newNode;
            } else
                parent = parent->child[iter-parent->childVal.begin()];
        }
    }

    dfs(root, -1);
}