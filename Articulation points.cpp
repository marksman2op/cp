// Find articulation points in an undirected graph
set<int> articulation;    // Same vertices can be reported multiple times

void dfs_articulation(int v, int p = -1) {    // Run this for each connected component
    vis[v] = true;
    in[v] = low[v] = timer++;
    int children = 0;
    for (int u : adj[v]) {
        if (u == p) 
            continue;
        if (vis[u]) {
            low[v] = min(low[v], in[u]);
        } 
        else {
            dfs_articulation(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= in[v] && p != -1) 
                articulation.insert(v);
            children++;
        }
    }
    if(p == -1 && children > 1)
        articulation.insert(v);
}
