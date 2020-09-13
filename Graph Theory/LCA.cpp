/*  
    LCA using Binary Lifting
    Distance between 2 nodes = lvl[u] + lvl[v] - 2 * lvl[lca(u, v)]
    Find k-th ancestor: https://www.hackerearth.com/challenges/competitive/data-structures-and-algorithms-coding-contest-september-2020/algorithm/family-tree-of-aman-f2e011b3/
*/

int l;
vector<vector<int>> anc;     // anc[i][j] is the 2^j-th ancestor of the node i 

void dfs_lca(int v, int p) {
    in[v] = timer++;
    anc[v][0] = p;
    for (int i = 1; i <= l; i++)
        anc[v][i] = anc[anc[v][i - 1]][i - 1];

    for (int u : adj[v]) {
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

void pre(int r) {
    l = ceil(log2(n));
    anc.assign(n + 1, vector<int>(l + 1));   
    dfs_lca(r, r);
}
