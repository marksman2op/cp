// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> solve(vector<pair<int, int>> a) {
    int n = a.size();
    sort(a.begin(), a.end(), [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
        return x.second < y.second;
    });

    vector<int> res; 
    int x = a[0].second; 
    res.push_back(x);
    for (int i = 1; i < n; i++) {
        if (x < a[i].first || x > a[i].second) { 
            x = a[i].second; 
            res.push_back(x); 
        }
    }

    return res;
}

// Minimum number of points required such that all line segments have atleast one point.
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            a[i] = {l, r};
        } 

        vector<int> ans = solve(a);
        cout << ans.size() << '\n';
        for (auto && x : ans) 
            cout << x << ' ';
        cout << '\n';
        
    }
    
    return 0;
}

