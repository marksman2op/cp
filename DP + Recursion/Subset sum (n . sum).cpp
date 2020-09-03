// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105; 
const int M = 105 * 1005;

int n, k, a[N];
bool dp[N][M];

// Space efficient: https://www.geeksforgeeks.org/subset-sum-problem-osum-space/
// dp[i][j] = Can we make j sum using first i elements

// Similar problem: https://www.geeksforgeeks.org/subset-sum-divisible-m/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    cin >> T; 
    while (T--) {
        cin >> n >> k;
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            tot += a[i];
        }

        dp[0][0] = true;
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= tot; j++) {
                    dp[i][j] = dp[i - 1][j]; 
                if (j >= a[i]) 
                    dp[i][j] |= dp[i - 1][j - a[i]]; 
            } 
        } 


        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 25; j++)
        //         cout << dp[i][j] << ' ';
        //     cout << '\n';
        // }

        cout << (dp[n][k] ? "YES" : "NO") << '\n';

    }
    
    return 0;
}

