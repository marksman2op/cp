// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Tree rerooting technique
    - https://codeforces.com/blog/entry/76150
    - https://codeforces.com/blog/entry/68139

    Problems
    - https://cses.fi/problemset/task/1130/
    - https://codeforces.com/contest/1187/problem/E
    - https://codeforces.com/contest/219/problem/D
    - https://codeforces.com/contest/1324/problem/F
    - https://codeforces.com/contest/1092/problem/F
    - https://codeforces.com/contest/766/problem/E
    - https://codeforces.com/contest/960/problem/E
*/

const int N = 2e5 + 5;
int n, m;
vector<int> g[N], sz(N), dp(N), ans(N);

void dfs(int v, int p) {
    sz[v] = 1;
    for (auto &&u : g[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
            dp[v] += dp[u];
        }
    }
    dp[v] += sz[v];
}

void go(int v, int p) {
    for (auto &&u : g[v]) {
        if (u != p) {
            // Rerooting from v to u
            dp[v] -= dp[u] + sz[u];
            sz[v] -= sz[u];
            sz[u] += sz[v];
            dp[u] += dp[v] + sz[v];
            
            ans[u] = dp[u];
            go(u, v);

            // Revert back changes
            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            sz[v] += sz[u];
            dp[v] += dp[u] + sz[u];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, -1);
        // for (int i = 1; i <= n; i++)
        //     cout << sz[i] << ' ';
        // cout << '\n';
        // for (int i = 1; i <= n; i++)
        //     cout << dp[i] << ' ';
        // cout << '\n';
        
        ans[1] = dp[1];
        go(1, -1);

        int res = *min_element(ans.begin() + 1, ans.begin() + n + 1);
        cout << res << '\n';
        for (int i = 1; i <= n; i++) {
            if (ans[i] == res)
                cout << i << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
