// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*  
    LCA using Binary Lifting
    - anc[v][k] is the 2^k-th ancestor of the node v
    - anc[v][k + 1] = anc[anc[v][k]][k]
    Distance between 2 nodes = lvl[u] + lvl[v] - 2 * lvl[lca(u, v)]
    
    Problems
    - https://www.hackerearth.com/challenges/competitive/data-structures-and-algorithms-coding-contest-september-2020/algorithm/family-tree-of-aman-f2e011b3/
    - https://www.spoj.com/problems/DISQUERY/ 
*/

const int N = 1e5 + 5;
int n, l, timer;
vector<int> g[N], in(N), out(N);
vector<vector<int>> anc;   

void dfs_lca(int v, int p) {
    in[v] = timer++;
    anc[v][0] = p;
    for (int i = 1; i <= l; i++)
        anc[v][i] = anc[anc[v][i - 1]][i - 1];

    for (int u : g[v]) {
        if (u != p)
            dfs_lca(u, v);
    }

    out[v] = timer++;
}

bool is_ancestor(int u, int v) {
    return (in[u] <= in[v] && out[u] >= out[v]);
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; i--) {
        if (!is_ancestor(anc[u][i], v))
            u = anc[u][i];
    }
    return anc[u][0];
}

void pre(int v) {
    l = ceil(log2(n));
    anc.assign(n + 1, vector<int>(l + 1));   
    dfs_lca(v, v);
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

        pre(1);
    }
    
    return 0;
}

