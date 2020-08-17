// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int n, m, u, v;
vector<int> adj[N], rg[N], vec, comp;
vector<bool> vis(N);

void dfs(int v) {
    vis[v] = true;
    for (auto u : adj[v]) {
        if(!vis[u])
            dfs(u);
    }
    vec.push_back(v);
}

void dfs_rev(int v, int k) {
    comp[v] = k;
    for (auto u : rg[v]) {
        if (comp[u] == -1)
            dfs_rev(u, k);
    }
}

void kosaraju() {
    int cnt = 0;
    comp.resize(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i);
    }

    reverse(vec.begin(), vec.end());

    for (auto v : vec) {
        if (comp[v] == -1)
            dfs_rev(v, ++cnt);
    }

    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n >> m;
        while (m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            rg[v].push_back(u);
        }        

        kosaraju();
    }
    
    return 0;
}

