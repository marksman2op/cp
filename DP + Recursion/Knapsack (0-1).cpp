// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Knapsack without repetitions
int solve(int w, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[n][w];
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, w;
        cin >> n >> w;
        vector<int> val(n), wt(n);
        for (int i = 0; i < n; i++) 
            cin >> val[i];
        for (int i = 0; i < n; i++)
            cin >> wt[i];

        cout << solve(w, val, wt) << '\n';
    }
    
    return 0;
}

