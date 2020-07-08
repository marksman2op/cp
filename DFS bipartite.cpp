// Check bipartite using dfs
bool ok = 1;
vector<int> col(N, -1);
void dfs_bipartite(int v, int c = 0) {    // Run this for each connected component
    vis[v] = 1;
    col[v] = c;
    for (auto u : adj[v]) {
        if (col[u] == -1) 
            dfs_bipartite(u, c ^ 1);
        else if (col[u] == col[v]) 
            ok = false;
    }
}
