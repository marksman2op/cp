// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*  
    Rod cutting
    https://www.youtube.com/watch?v=IRwVmTmN6go
    Space efficient: https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int dp[n + 1][n + 1] = {};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i <= j)
                    dp[i][j] = max(dp[i][j], dp[i][j - i] + a[i]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << dp[i][j] << ' ';
            cout << '\n';
        }

        cout << dp[n][n] << '\n';
        
    }
    
    return 0;
}

