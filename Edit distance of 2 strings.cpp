// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Edit distace
// Optimal alignment can be found using backtracking the DP.
int solve(string s, string t) { // Finds edit distace of strings s and t
    int dp[105][105] = {};
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for (int i = 0; i < 105; i++)
        dp[i][0] = dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (s[i] == t[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); 
        }
    }
    return dp[n][m];
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        string s, t;
        cin >> s >> t;

        cout << solve(s, t) << '\n';
    }
    
    return 0;
}

