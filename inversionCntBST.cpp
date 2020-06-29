// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int NX = 2e5 + 5;

int n, a[NX];

// AVL tree
struct Node { 
    int key, height; 
    Node* left;
    Node* right;   
    int size; // Size of tree rooted at this node
}; 

int height(Node* N) { // Height of tree rooted with N 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

int size(Node* N) { // Size of tree rooted with N 
    if (N == NULL) 
        return 0; 
    return N->size; 
} 

Node* newNode(int key) { 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = NULL;
    temp->right  = NULL; 
    temp->height = 1;
    temp->size = 1; 
    return temp; 
} 

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) { 
    Node* x = y->left; 
    Node* T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right)) + 1; 
    x->height = max(height(x->left), height(x->right)) + 1; 
  
    // Update sizes 
    y->size = size(y->left) + size(y->right) + 1; 
    x->size = size(x->left) + size(x->right) + 1; 
  
    // Return new root 
    return x; 
} 

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) { 
    Node* y = x->right; 
    Node* T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right)) + 1; 
    y->height = max(height(y->left), height(y->right)) + 1; 
  
    // Update sizes 
    x->size = size(x->left) + size(x->right) + 1; 
    y->size = size(y->left) + size(y->right) + 1; 
  
    // Return new root 
    return y; 
} 

int balanceFactor(Node* N) { 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

// Insert new key to the tree rotted with node.
Node* insert(Node* node, int key, int* res) {
    // 1. Perform the normal BST rotation 
    if (node == NULL) 
        return newNode(key); 
  
    if (key < node->key) { 
        node->left  = insert(node->left, key, res); 
        *res = *res + size(node->right) + 1; 
    } 
    else
        node->right = insert(node->right, key, res); 
  
    // 2. Update height and size of this ancestor node
    node->height = max(height(node->left), height(node->right)) + 1; 
    node->size = size(node->left) + size(node->right) + 1; 
  
    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced 
    int bal = balanceFactor(node); 
  
    // If this node becomes unbalanced, then there are 4 cases: 
  
    // A. Left Left Case 
    if (bal > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // B. Right Right Case 
    if (bal < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // C. Left Right Case 
    if (bal > 1 && key > node->left->key) { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // D. Right Left Case 
    if (bal < -1 && key < node->right->key) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    // return the (unchanged) node pointer 
    return node; 
} 

int cntInversion() { 
    int res = 0; 
    struct Node *root = NULL;  
    for(int i = 0; i < n; i++) 
        root = insert(root, a[i], &res); 

    return res; 
} 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    cin >> T; 
    while (T--) {
        cin >> ws >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        cout << cntInversion() << '\n';
    }
    
    return 0;
}

