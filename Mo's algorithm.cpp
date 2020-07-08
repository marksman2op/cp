// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

//https://www.spoj.com/problems/DQUERY/

/* 
    Mo's Algorithm: 
    - Requirements
        - Array is not changed by queries.
        - All queries are known beforehand.
        - If we know Func([L, R]), then we can compute Func([L ± 1, R ± 1]) each in O(F) time.
    - Time Complexity: O((N + Q) * SQRT(N) * F) 
    - SQRT decomidxition of array 
        - Divide the given input array into sqrt(N) blocks.
        - Each block will be N / sqrt(N) = sqrt(N) size.
    - Optimal ordering of queries       
        - A query belongs to P'th block if the opening of that query (i.e. L) fall in P'th block
    
    - Sources: 
        - https://blog.anudeep2011.com/mos-algorithm/
        - https://www.hackerearth.com/practice/notes/mos-algorithm/

*/

const int N = 1e6 + 5;

int n, q, sz, curr, h[N];
vector<int> arr, ans;
vector<pair<pair<int, int >, int> > queries;

bool comp(const pair<pair<int, int>, int> &x, const pair<pair<int, int>, int> &y) {
    int rx = x.first.first / sz;
    int ry = y.first.first / sz;
    if (rx != ry)
        return rx < ry;
    return x.first.second < y.first.second;
}

// When updating, first nullify current idxitions affect and then update.
void add(int x) {
    h[x]++;
    if (h[x] == 1)
        curr++;
}

void remove(int x) {
    h[x]--;
    if (h[x] == 0)
        curr--;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        sz = sqrt(n);
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> q;
        queries.resize(q);
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            queries[i] = {{l, r}, i};
        }
        sort(queries.begin(), queries.end(), comp);
        
        int ml = 0, mr = -1;
        ans.resize(q);
        for (int i = 0; i < q; i++) {
            int ql = queries[i].first.first;
            int qr = queries[i].first.second;
            int idx = queries[i].second;

            //Moving ml and mr
            while(mr < qr) {
                mr++;
                add(arr[mr]);
            }
            while(mr > qr) {
                remove(arr[mr]);
                mr--;
            }

            while(ml < ql) {
                remove(arr[ml]);
                ml++;
            }
            while(ml > ql) {
                ml--;
                add(arr[ml]);
            }

            ans[idx] = curr;
        }

        for (int i = 0; i < q; i++)
            cout << ans[i] << '\n';
        cout << '\n';
    }
    
    return 0;
}

