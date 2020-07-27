// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> solve(vector<pair<int, int> > seg, vector<int> pts) {
    int n = seg.size(), m = pts.size();
    vector<pair<int, int> > sx, px;
    for (int i = 0; i < n; i++) {
        sx.push_back({seg[i].first, 1});
        sx.push_back({seg[i].second + 1, -1});
    }
    sort(sx.begin(), sx.end(), greater<pair<int, int>>());
    for (int i = 0; i < m; i++)
        px.push_back({pts[i], i});
    sort(px.begin(), px.end());

    int cnt = 0;
    vector<int> res(m);
    for(int i = 0; i < m; i++) { 
        int x = px[i].first; 
        while(!sx.empty() && sx.back().first <= x) { 
            cnt += sx.back().second; 
            sx.pop_back(); 
        }
        res[px[i].second] = cnt; 
    } 
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int> > seg(n);
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            seg[i] = {l, r};
        }   
        vector<int> pts(m);
        for (int i = 0; i < m; i++)
            cin >> pts[i];

        vector<int> ans = solve(seg, pts);
        for (auto && x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    
    return 0;
}

