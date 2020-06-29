// Cycle detection using BFS
vector<int> v1, v2;
vector<int> par(N, -1);

void LCA_cycle(int u, int v) {
    v1.push_back(u);
    v2.push_back(v);
    if(u == v)
        return;
 
    if(par[u] == v) {
        v1.push_back(v);
        return;
    }
    if(par[v] == u) {
        v2.push_back(u);
        return;
    }
 
    LCA_cycle(par[u], par[v]);
    return;

    // vector<int> path;
    // for(int i = 0; i < v1.size(); i++) 
    //     path.push_back(v1[i]);
    // for(int i = (int)v2.size() - 2; i >= 0; i--)
    //     path.push_back(v2[i]);
}
 
void bfs_cycle(int s) {
    queue<int> q;
    q.push(s);
    par[s] = -1;
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
 
        for(auto u : adj[v]) {
            if(par[u] && par[v] != u) {
                LCA_cycle(u, v);
                return;
            }
            if(!par[u]) {
                q.push(u);
                par[u] = v;
            }
        }
    }
}
