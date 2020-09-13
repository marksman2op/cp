// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    https://www.geeksforgeeks.org/painting-fence-algorithm/
    https://medium.com/@xiaogegexiao/interesting-paint-fence-algorithm-36e7e2ab4111
    f(n) = f(n - 1) * k - f(n - 3) * (k - 1)
*/

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, k, dp[N];

int solve(int n) {
    // if (n == 1)
    //     return k;
    // if (n == 2) 
    //     return k * k;
    // if (n == 3)
    //     return k * (k - 1 + (k - 1) * k);
    if (k < 2 && n > 2) 
        return 0;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (solve(n - 1) * k % mod - solve(n - 3) * (k - 1) % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    cin >> T; 
    while (T--) {
        cin >> n >> k;

        memset(dp, -1, sizeof(dp));
        dp[1] = k;
        dp[2] = k * k;
        dp[3] = k * (k - 1 + (k - 1) * k);

        cout << solve(n) << '\n';
    }
    
    return 0;
}

