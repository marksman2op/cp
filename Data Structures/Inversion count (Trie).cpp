// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, a[N];

struct Node {
    int cnt;
    Node* left;
    Node* right;
};

Node* newNode() {
    Node* temp = new Node;
    temp->cnt = 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(int val, Node* root, int& res) {
    for(int i = 63; i >= 0; i--) {
        int bit = (val & (1 << i));
        if(bit != 0) {
            if(root->left != NULL) 
                res += root->left->cnt; 

            if(root->right != NULL) { 
                root = root->right; 
                root->cnt++; 
            } 
            else {
                Node* temp = newNode();
                root->right = temp;
                root = root->right;
            }
        }
        else {
            if(root->left != NULL) { 
                root = root->left; 
                root->cnt++; 
            } 
            else { 
                Node* temp = newNode(); 
                root->left = temp; 
                root = root->left; 
            } 
        }
    }
}

int cntInversion() {
    int res = 0;
    Node* head = newNode();
    for(int i = n - 1; i >= 0; i--) {
        insert(a[i], head, res);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        cout << cntInversion() << '\n';
    }
    
    return 0;
}

