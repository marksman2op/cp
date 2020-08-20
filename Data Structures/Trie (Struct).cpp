// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node { 
    Node *child[30]; 
    bool eow; // isEndOfWord
}; 
  
struct Node *getNode(void) { 
    Node *temp =  new Node; 
    temp->eow = false; 
    for (int i = 0; i < 30; i++) 
        temp->child[i] = NULL; 
    return temp; 
} 
   
void insert(Node *root, string s) { 
    Node *curr = root; 
    for (int i = 0; i < s.size(); i++) { 
        int idx = s[i] - 'a'; 
        if (!curr->child[idx]) 
            curr->child[idx] = getNode(); 
        curr = curr->child[idx]; 
    }  
    curr->eow = true; 
} 

bool search(Node *root, string s) { 
    Node *curr = root; 
    for (int i = 0; i < s.size(); i++) { 
        int idx = s[i] - 'a'; 
        if (!curr->child[idx]) 
            return false; 
        curr = curr->child[idx]; 
    } 
  
    return (curr != NULL && curr->eow); 
}  

// Returns true if curr has no children, else false 
bool isEmpty(Node* curr) { 
    for (int i = 0; i < 30; i++) 
        if (curr->child[i]) 
            return false; 
    return true; 
} 
  
// Recursive function to delete a key from given Trie 
Node* remove(Node* curr, string s, int i = 0) {
    if (!curr) 
        return NULL; 
   
    if (i == s.size()) { 
        if (curr->eow) 
            curr->eow = false; 
  
        // If given is not prefix of any other word 
        if (isEmpty(curr)) { 
            delete (curr); 
            curr = NULL; 
        } 
  
        return curr; 
    } 
  
    int idx = s[i] - 'a'; 
    curr->child[idx] = remove(curr->child[idx], s, i + 1); 
    if (isEmpty(curr) && curr->eow == false) { 
        delete (curr); 
        curr = NULL; 
    } 
    return curr; 
} 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        string keys[] = {"anil", "kumar", "marksman", "humble", "kumarfool", "mamgain"}; 
        int n = sizeof(keys) / sizeof(keys[0]); 
      
        Node* root = getNode(); 
        for (int i = 0; i < n; i++) 
            insert(root, keys[i]); 
       
        search(root, "marksman") ? cout << "Yes\n" : cout << "No\n";
        search(root, "marksma") ? cout << "Yes\n" : cout << "No\n";
        search(root, "marksmam") ? cout << "Yes\n" : cout << "No\n"; 
        remove(root, "marksman"); 
        search(root, "marksman") ? cout << "Yes\n" : cout << "No\n";
        
    }
    
    return 0;
}

