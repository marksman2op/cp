// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*  
    https://codeforces.com/contest/359/problem/D
    https://cp-algorithms.com/data_structures/sparse-table.html
*/

const int MAX_N = 3e5 + 5;
const int MAX_K = log2(MAX_N) + 1;
const int MAX_X = 1e6 + 5;
const int INF = 1e7 + 5;
const double EPS = 1e-7;
int n, a[MAX_N];

struct Data {
    int m, g; // MIN and GCD
    Data() {
    }
    Data(int _m, int _g) :
        m(_m), g(_g) {
    }
    Data(const Data& d) :
        m(d.m), g(d.g) {
    }
} st[MAX_N][MAX_K];

void merge(Data& p, const Data u, const Data v) {
    p.m = min(u.m, v.m);
    p.g = gcd(u.g, v.g);
}

void build() { 
    for (int i = 1; i <= n; i++) {
        st[i][0] = Data(a[i], a[i]);   
    }  
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; (1 << j) <= n - i + 1; j++) {
            merge(st[i][j], st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

Data query(int l, int r) {
    int j = log2(r - l + 1) + EPS;
    Data res;
    merge(res, st[l][j], st[r - (1 << j) + 1][j]);
    return res;
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build();

    auto check = [&](int mid) {
        for (int i = 1; i + mid <= n; i++) {
            int j = i + mid;
            Data res = query(i, j);
            if (res.g % res.m == 0) {
                return true;
            }
        }
        return false;
    };

    int lo = 0, hi = n - 1, last = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            last = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }   

    vector<int> vec;
    for (int i = 1; i + last <= n; i++) {
        int j = i + last;
        Data res = query(i, j);
        if (res.g % res.m == 0) {
            vec.push_back(i);
        }
    }

    cout << (int)vec.size() << ' ' << last << '\n';
    for (const auto x : vec) {
        cout << x << ' ';
    }
    cout << '\n';
    return;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++) {
        // cout << "Case #" << t << ": ";
        run_case();
    }
    
    return 0;
}