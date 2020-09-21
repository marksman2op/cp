// Kahn’s algorithm for Topological Sorting
vector<int> tsort;

bool kahn() {    // Returns true if topological sort exists, else false
    priority_queue<int> pq; // To find any topological sort
    // priority_queue<int, vector<int>, greater<int> > pq; // To find lexographically smallest topological sort
    
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) 
            pq.push(i);
    }

    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        tsort.push_back(v);

        for (auto u : adj[v]) {
            in[u]--;
            if (in[u] == 0)
                pq.push(u);
        }
    }

    return tsort.size() == n;
}

// Topological sort using DFS can be done as follows
void dfs_tsort(int v) {    // Assumes graph is not cyclic, Run for each connected component
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs_tsort(u);
    }
    tsort.push_back(v);
}
