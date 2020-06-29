// Calculate subtree size of each node
// To check if v lies in subtree of u: in[u] < in[v] && out[u] > out[v]
// What’s subtree of node x? elements of discover from position in[x] to out[x].
// Subtree size of v = (out[v] - in[v] + 1) / 2
vector<int> sz(N, 0);
int subtree_size(int v) {    
    vis[v] = 1;
    int cnt = 1;
    for(auto u : adj[v]) {
        if(!vis[u])
            cnt += subtree_size(u);
    }
    return sz[v] = cnt;
}
