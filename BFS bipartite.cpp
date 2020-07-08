// Check bipartite using bfs
bool bfs_bipartite() {    
    vector<int> col(N, -1);    // 2 sets are coloured 0 and 1.
    bool ok = true;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            q.push(i);
            col[i] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int u : adj[v]) {
                    if (col[u] == -1) {
                        col[u] = col[v] ^ 1;
                        q.push(u);
                    } 
                    else 
                        ok &= col[u] != col[v];
                }
            }
        }
    }

    return ok;
}
