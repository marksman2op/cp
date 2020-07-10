// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/* 
  Source: https://leetcode.com/articles/rectangle-area-ii/
  Idea: Segment tree + Linear sweep
  Time Complexity: O(N log N), where N is the number of rectangles.
*/

bool comp(vector<int> & a, vector<int> & b) {
    if(a[2] != b[2])
        return a[2] < b[2];
    return a[0] < b[0];
}

struct Node {
    int start, end; 
    int cnt, area; 
    Node *left, *right;
    Node(int s, int e, int cn, int ar, Node *l, Node *r) {
        start = s;
        end = e;
        cnt = cn;
        area = ar;
        left = l;
        right = r;
    }
};


Node* Build(vector<int> & A, int s, int e) {        
    if(s >= e)
        return NULL;
    if(e - s == 1)
        return new Node(A[s], A[s + 1], 0, 0, NULL, NULL);
        
    int mid = (s + e) / 2;
    Node *left = Build(A, s, mid);
    Node *right = Build(A, mid, e);
    return new Node(left->start, right->end, 0, 0, left, right);
}

void Update(Node *r, int s, int e,  int val) {
    if(!r)
        return;
    if(s >= r->end || e <= r->start)
        return;

    if(s <= r->start && e >= r->end)
        r->cnt += val;
    else {
        Update(r->left, s, e, val); 
        Update(r->right, s, e, val);
    }

    if(r->cnt)
        r->area = r->end - r->start;
    else {
        if(r->left && r->right)
            r->area = r->left->area + r->right->area;
        else
            r->area = 0;
    }
}

int rectangleArea(vector<vector<int>> & rect) {
    int n = rect.size();
    if (n == 0)
        return 0;

    set<int> sx;
    for (auto && v : rect) {
        sx.insert(v[0]);
        sx.insert(v[2]);           
    }
            
    vector<int> vx;
    for (auto && x : sx)
        vx.push_back(x);
        
    int res = 0;
    Node *root = Build(vx, 0, vx.size() - 1);        
    
    vector<vector<int>> vec;
    for (auto && v : rect) {
        vector<int> temp(4);
        temp[0] = v[0];
        temp[1] = v[2];
        temp[2] = v[1];
        temp[3] = 1;
        vec.push_back(temp);
        temp[2] = v[3];
        temp[3] = -1;
        vec.push_back(temp);            
    }
    sort(vec.begin(), vec.end(), comp);
    
    Update(root, vec[0][0], vec[0][1], vec[0][3]);
    for (int i = 1; i < vec.size(); i++) {
        int h = vec[i][2] - vec[i - 1][2];        
        int w = root->area;            
        if(h > 0)
            res += (h * w);
        Update(root, vec[i][0], vec[i][1], vec[i][3]);       
    }
    
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> rect;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            rect.push_back({a, b, c, d});
        }
        
        int ans = rectangleArea(rect);
        cout << ans << '\n';
        
    }
    
    return 0;
}

