// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Z function
    - Z[i] = length of the longest substring starting from S[i] which is also a prefix of S
    - z[i] = x means substrings [0..j) [i..i+j) are equals for all j from 0 to (x - 1).
    - https://codeforces.com/blog/entry/3107
    - Z-function and prefix-function are equivalent (one can  transform Z<->prefix in O(n)). 
    - https://codeforces.com/blog/entry/9612
    - Often it is easier to think in terms of Z-function to solve a problem.
*/

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// https://codeforces.com/problemset/problem/432/D

// https://www.codechef.com/problems/CHSTR
// https://discuss.codechef.com/t/chstr-editorial/11135/28

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        string s;
        cin >> s;

        int n = s.size();
        auto z = z_function(s);
        
        // for (int i = 0; i < n; i++)
        //     cout << z[i] << ' ';
        // cout << '\n';

        int cnt[n + 1] = {};
        for (int i = 0; i < n; i++) 
            cnt[z[i]]++;
        for (int i = n - 1; i >= 0; i--) 
            cnt[i] += cnt[i + 1];
        for (int i = 0; i < n; i++)
            cnt[i]++;
         
        // for (int i = 0; i < n; i++)
        //     cout << cnt[i] << ' ';
        // cout << '\n';

        bool ok[n + 1] = {};
        int tot = 1;
        for (int i = 0; i < n; i++) {
            if (z[n - 1 - i] == i + 1) {
                ok[i] = true;
                tot++;
            }
        }
        ok[n] = true;

        cout << tot << '\n';
        for (int i = 0; i < n; i++) {
            if (ok[i])
                cout << i + 1 << ' ' << cnt[i + 1] << '\n';
        }
        cout << n << ' ' << 1 << '\n';
    }
    
    return 0;
}

