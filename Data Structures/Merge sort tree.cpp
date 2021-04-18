// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Merge sort tree
        - https://discuss.codechef.com/t/merge-sort-tree-tutorial/14277
        - https://cp-algorithms.com/data_structures/segment_tree.html

    Problems:
        - https://www.hackerearth.com/challenges/competitive/april-circuits-21/algorithm/smallest-subarray-2-d6530e0b/
        - https://codeforces.com/contest/1042/problem/D
*/

const int N = 2e5 + 5;
int a[N], sum[N];
vector<int> tree[4 * N];

void build(int v, int tl, int tr) { // build(1, 1, n)
    if (tl == tr) {
        tree[v].push_back(sum[tl]);
    } else {
        int mid = (tl + tr) / 2;
        int l = 2 * v, r = 2 * v + 1;
        build(l, tl, mid);
        build(r, mid + 1, tr);
        merge(tree[l].begin(), tree[l].end(), tree[r].begin(), tree[r].end(), back_inserter(tree[v]));
    }
}

int query(int ql, int qr, int l, int r, int v, int x) { // query(ql, qr, 1, n, 1, val)
    if (l > qr || r < ql) {
        return 0;
    } else if (l >= ql && r <= qr) {
        int res = lower_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin();
        return res;
    } else {
        int mid = (l + r) / 2;
        return query(ql, qr, l, mid, 2 * v, x) + query(ql, qr, mid + 1, r, 2 * v + 1, x);
    }
}

void run_case() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    build(1, 1, n);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += query(i, n, 1, n, 1, sum[i - 1] + k);
    }
    cout << res << '\n';
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