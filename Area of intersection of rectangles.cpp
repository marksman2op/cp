#include<bits/stdc++.h>
using namespace std;
#define int long long

/* 
  Source: https://leetcode.com/articles/rectangle-area-ii/
  Idea: Segment tree + Linear sweep
  Time Complexity: O(N log N), where N is the number of rectangles.
*/

class Rectangle {
    public:
        int x1, y1, x2, y2;
    
        static Rectangle empty;
        
        Rectangle() {
            x1 = y1 = x2 = y2 = 0;
        }

        Rectangle(int X1, int Y1, int X2, int Y2) {
            x1 = X1; 
            y1 = Y1;
            x2 = X2; 
            y2 = Y2;
        }

        Rectangle intersect(Rectangle R) {
            if(R.x1 >= x2 || R.x2 <= x1 || R.y1 >= y2 || R.y2 <= y1) 
                return empty;
            return Rectangle(max(x1, R.x1), max(y1, R.y1), min(x2, R.x2), min(y2, R.y2));
        }
};

struct Event {
    int x, y1, y2, type;
    Event() {}
    Event(int x, int y1, int y2, int type) : x(x) , y1(y1) , y2(y2) , type(type) {}
};

bool operator < (const Event & A, const Event & B) {
    return A.x < B.x;
}

const int MX = 1005;

struct Node {
    int prob, sum, ans;
    Node() {}
    Node(int prob, int sum, int ans) : prob(prob), sum(sum), ans(ans) {}
};

Node tree[4 * MX];
int interval[MX];
void build(int idx, int l, int r) {
    tree[idx] = Node(0 , 0 , 0);
    if (l == r) {
        tree[idx].sum += interval[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    tree[idx].sum = tree[2 * idx].sum + tree[2 * idx + 1].sum;
}

int query(int idx){
    if (tree[idx].prob) 
        return tree[idx].sum;
    return tree[idx].ans;
}

int st, en, val;
void update(int idx, int l, int r) {
    if (st > r || en < l) 
        return;
    if (l >= st && r <= en) {
        tree[idx].prob += val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * idx, l, mid);
    update(2 * idx + 1, mid + 1 , r);
    tree[idx].ans = query(2 * idx) + query(2 * idx + 1);
}

Rectangle Rectangle::empty = Rectangle();
vector<Rectangle> rect;
vector<int> sorted;
vector<Event> sweep;

void compression() {
    for (auto p : rect) {
        sorted.push_back(p.y1);
        sorted.push_back(p.y2);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    int sz = sorted.size();
    for (int i = 0; i < (int)sorted.size() - 1; i++)
        interval[i + 1] = sorted[i + 1] - sorted[i];

    for (auto p : rect){
        sweep.push_back(Event(p.x1, p.y1, p.y2, 1));
        sweep.push_back(Event(p.x2, p.y1, p.y2, -1));
    }
    sort(sweep.begin() , sweep.end());

    build(1, 1, sz - 1);
}

int ans;
void linearSweep() {
    if (sorted.empty() || sweep.empty()) 
        return;

    int lt = 0, sz = sorted.size();
    for (int i = 0; i < (int)sweep.size(); i++){
        ans += (sweep[i].x - lt) * query(1);
        lt = sweep[i].x;
        val = sweep[i].type;
        st = lower_bound(sorted.begin() , sorted.end() , sweep[i].y1) - sorted.begin() + 1;
        en = lower_bound(sorted.begin() , sorted.end() , sweep[i].y2) - sorted.begin();
        update(1 , 1 , sz - 1);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            rect.push_back(Rectangle(a, b, c, d));
        }

        compression();
        linearSweep();
        
        cout << ans << '\n';
    }
    
    return 0;
}
