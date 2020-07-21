// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

// Works in O(n log(n))
struct pt {
    int x, y, id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

int n;
vector<pt> a;

double mindist;
pair<int, int> best_pair;

void upd_ans(const pt & a, const pt & b) {
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}

vector<pt> t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        a.resize(n);
        int sx[n], sy[n];
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            a[i].x = x;
            a[i].y = y;
            a[i].id = i;
        }

        t.resize(n);
        sort(a.begin(), a.end(), cmp_x());
        mindist = 1E20;
        rec(0, n);

        int f = best_pair.first, s = best_pair.second;
    }
    
    return 0;
}

