// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://www.geeksforgeeks.org/maximum-number-segments-lengths-b-c/
// https://www.geeksforgeeks.org/maximize-the-number-of-segments-of-length-p-q-and-r/

const int INF = 1e10;

int n, a, b, c;
int dp[4005];

int solve(int n) {
    if (n < 0)
        return -INF;
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int A = solve(n - a);
    int B = solve(n - b);
    int C = solve(n - c);

    return dp[n] = max({A, B, C}) + 1;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n >> a >> b >> c;

        memset(dp, -1, sizeof(dp));
        cout << solve(n) << '\n';
    }
    
    return 0;
}

