// SSSP for trees
vector<int> lvl(N, -1);    
void dfs_sssp(int v, int dpt = 0) {
    vis[v] = true;
    lvl[v] = dpt;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs_sssp(u, lvl[v] + 1);
    }
}
