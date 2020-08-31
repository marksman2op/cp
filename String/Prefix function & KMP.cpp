// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Prefix function:
    - pi[i] =  Length of the longest proper prefix of the substring s[:i] which is also a suffix of this substring.
    - Proper prefix = Prefix that is not equal to the string itself
    - Works in O(n)
    - If pi[i] = x, it means [0..j) = (i-j..i] for all j = x, p[x], p[p[x]] and so on.
    - Longest prefix suffix (lps)
    - Z- function is more intuitive.


    KMP Algorithm
    - Make new string temp = s + "#" + t
    - Find prefix function of temp
    - If (pi[i] == pat.size()), then matching pattern starts at (i - 2 * s.size()) (0 - based) 

*/

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    cin >> T; 
    while (T--) {
        string t, s;
        cin >> t >> s;

        // Pattern Matching (KMP)
        string st = s + "#" + t; 
        auto pi = prefix_function(st);

        vector<int> res;
        for (int i = 0; i < pi.size(); i++) {
            if (pi[i] == s.size())
                res.push_back(i - 2 * s.size() + 1);
        }

        cout << res.size() << '\n';
        for (auto &&x : res)
            cout << x << ' ';
        cout << '\n';

        // Number of occourance of each prefix
        int n = t.size();
        pi = prefix_function(t);
        int cnt[n + 1] = {};
        for (int i = 0; i < n; i++)
            cnt[pi[i]]++;
        for (int i = n - 1; i > 0; i--) 
            cnt[pi[i - 1]] += cnt[i];
        for (int i = 0; i <= n; i++)
            cnt[i]++;

        for (int i = 1; i <= n; i++)
            cout << cnt[i] << ' ';
        cout << '\n';

    }
    
    return 0;
}

