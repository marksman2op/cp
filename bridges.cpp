// Find bridges in an undirected graph
vector<pair<int, int >> bridge;
vector<int> low(N, -1);

void dfs_bridge(int v, int p = -1) {    // Run this for each connected component
    vis[v] = true;
    in[v] = low[v] = timer++;
    for (int u : adj[v]) {
        if (u == p) 
            continue;
        if (vis[u])    // Back edges can never be bridges, so we have to check only tree edges.
            low[v] = min(low[v], in[u]); 
        else {
            dfs_bridge(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > in[v])
                bridge.push_back({v, u});
        }
    }
}
