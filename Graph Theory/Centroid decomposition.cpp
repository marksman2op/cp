// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Centroid Decomposition:
    - https://medium.com/carpanese/an-illustrated-introduction-to-centroid-decomposition-8c1989d53308
    - https://www.quora.com/q/threadsiiithyderabad/Centroid-Decomposition-of-a-Tree
    - Mostly used when you want to count something on a tree, especially when it's related to a path.

    Properties:
    - The height of the centroid tree is atmost O(log N).
    - Consider any two arbitrary vertices A and B and the path between them (in the original tree) can be broken 
      down into A -> C and C -> B where C = LCA(A, B) the centroid tree.
    - Time taken to build centroid tree = O(N * log(N))

    Problems:
    - https://codeforces.com/problemset/problem/342/E
    - https://www.spoj.com/problems/QTREE5/
*/

const int N = 1e5 + 5, L = ceil(log2(N)), INF = 1e9;
int n, q, timer;
set<int> g[N];
vector<int> in(N), out(N), lvl(N), sz(N), ans(N, INF), ctPar(N);
vector<vector<int>> anc(N, vector<int> (L));   

void dfs_lca(int v, int p, int d) { // O(N * log(N))
    lvl[v] = d;
    anc[v][0] = p;
    in[v] = timer++;
    
    for (int i = 1; i <= L; i++)
        anc[v][i] = anc[anc[v][i - 1]][i - 1];

    for (auto &&u : g[v]) {
        if (u != p) 
            dfs_lca(u, v, d + 1);
    }

    out[v] = timer++;
}

bool is_ancestor(int u, int v) { // O(1)
    return (in[u] <= in[v] && out[u] >= out[v]);
}

int lca(int u, int v) { // O(log(N))
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L; i >= 0; i--) {
        if (!is_ancestor(anc[u][i], v))
            u = anc[u][i];
    }
    return anc[u][0];
}

int dist(int u, int v) { // O(log(N))
    return lvl[u] + lvl[v] - 2 * lvl[(lca(u, v))];
}

int dfs_centroid(int v, int p, int s) { // Find Centroid
    for (auto &&u : g[v]) {
        if (u != p && sz[u] > s / 2)
            return dfs_centroid(u, v, s);
    }
    return v;
}

void dfs_sz(int v, int p) {
    sz[v] = 1;
    for (auto &&u : g[v]) {
        if (u != p) {
            dfs_sz(u, v);
            sz[v] += sz[u];
        }
    }
}

// Centroid decomposition
void decompose(int v, int p) { // O(N * log(N))
    dfs_sz(v, -1);
    int c = dfs_centroid(v, v, sz[v]);
    if (p == -1)
        p = c; // Root of centroid tree
    ctPar[c] = p;

    for (auto &&u : g[c]) {
        g[u].erase(c);
        decompose(u, c);
    }
    g[c].clear();
}

// Traverse in centroid tree, ans[parent] = min(ans[parent], dist(node, parent))
void update(int v) { // O(log(N) * log(N))
    int u = v;
    while (true) {
        ans[u] = min(ans[u], dist(u, v));
        if (u == ctPar[u]) 
            break;
        u = ctPar[u];
    }
}

// Traverse in centroid tree and check each parent upto root
int query(int v) { // O(log(N) * log(N))
    int res = INF, u = v;
    while (true) {
        res = min(res, dist(u, v) + ans[u]);
        if (u == ctPar[u]) 
            break;
        u = ctPar[u];
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
        }

        dfs_lca(1, 1, 0);
        decompose(1, -1); // log(N * log(N))
        update(1);

        while (q--) { // Q * log(N) * log(N)
            int t, v;
            cin >> t >> v;
            if (t == 1)
                update(v);
            else
                cout << query(v) << '\n';
        }
    }
    
    return 0;
}

