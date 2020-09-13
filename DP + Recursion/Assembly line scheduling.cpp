// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Assembly line scheduling
    https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/  

    We have two assembly lines, 1 and 2, each with stations from 1 to n.
    e[i]: entry time in assembly line i [here i = 0, 1]
    x[i]: exit time from assembly line i
    a[i, j]: Time required at station S[i, j] (assembly line i, station j)
    t[i, j]: Time required to transit from station S[i, j] to the other assembly line.  
*/

const int N = 1005;

int n, a[2][N], t[2][N], e[2], x[2];

int solve() {
    int dp[2][N] = {};
    dp[0][0] = e[0] + a[0][0];
    dp[1][0] = e[1] + a[1][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = min(dp[0][i - 1] + a[0][i], dp[1][i - 1] + t[1][i] + a[0][i]);
        dp[1][i] = min(dp[1][i - 1] + a[1][i], dp[0][i - 1] + t[0][i] + a[1][i]);
    }

    int res = min(dp[0][n - 1] + x[0], dp[1][n - 1] + x[1]);
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        for (int j : {0, 1}) {
            for (int i = 0; i < n; i++)
                cin >> a[j][i]; 
        }
        for (int j : {0, 1}) {
            for (int i = 0; i < n; i++)
                cin >> t[j][i]; 
        }
        cin >> e[0] >> e[1];
        cin >> x[0] >> x[1];

        cout << solve() << '\n';
    }
    
    return 0;
}

