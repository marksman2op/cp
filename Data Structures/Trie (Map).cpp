// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*  
    Trie 
    - https://codeforces.com/blog/entry/43611
    - LCP (Longest Common Prefix) of two strings is the LCA (Lowest Common Ancestor) of their nodes.
    - Time Complexity: O(|key| * log(k))
    - Space complexity: O(Σ |strings|)

    - https://www.quora.com/q/threadsiiithyderabad/Tutorial-on-Trie-and-example-problems
    - https://ideone.com/FcLqQw
*/

// https://codeforces.com/problemset/problem/455/B

struct Node {
    bool isEnd;
    Node *parent;
    map<char, Node *> child;
    Node(Node *parent = NULL)
        : parent(parent), isEnd(false), child()
    {}
};
 
Node *trie_search(Node *root, string str) {
    Node *it;
    int i = 0, n = str.size();
    for (it = root; i < n; i++) {
        if (it->child.find(str[i]) == it->child.end())
            return NULL;
        it = it->child[str[i]];
    }

    return (it->isEnd) ? it : NULL;
}
 
void trie_insert(Node *root, string str) {
    Node *it;
    int i = 0, n = str.size();
    for (it = root; i < n; i++) {
        if (it->child.find(str[i]) == it->child.end())
            it->child[str[i]] = new Node(it);
        it = it->child[str[i]];
    }
    it->isEnd = true;
}
 
void trie_erase(Node *root, string str) {
    Node *it;
    int i = 0, n = str.size();
    for (it = root; i < n; i++) {
        if (it->child.find(str[i]) == it->child.end())
            return;
        it = it->child[str[i]];
    }
    it->isEnd = false;

    while (it->parent != NULL) {
        if (it->child.size() > 0 || it->isEnd)
            break;
        it = it->parent, i--;
        it->child.erase(str[i]);
    }
}

int dfs(Node *root) {
    int res = 0;
    bool got = false;
    for (char c = 'a'; c <= 'z'; c++) {
        if (root->child.find(c) != root->child.end()) {
            got = true;
            res |= dfs(root->child[c]) ^ 3;
        }
    }
    if(!got)
        res = 2;

    return res;
}

void print(int n) {
    if (n == 1)
        cout << "First\n";
    else
        cout << "Second\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, k;
        cin >> n >> k;
        Node *root = new Node();
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            trie_insert(root, s);
        }

        int ok = dfs(root);
        if (ok == 0 || ok == 2)
            print(2);
        else if (ok == 1)
            print(k % 2);
        else
            print(1);
    }
    
    return 0;
}

