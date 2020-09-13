/*
    DFS
    - Applications: https://cp-algorithms.com/graph/depth-first-search.html
    - SSSP on tree  
    - In-Out time of nodes
    - Diameter of tree (https://codeforces.com/blog/entry/60440)
    - Centroids of tree (https://codeforces.com/blog/entry/57593)
    - Calculate subtree size of each node in tree
        - To check if v lies in subtree of u: in[u] < in[v] && out[u] > out[v]
        - What’s subtree of node x? elements of discover from position in[x] to out[x].
        - Subtree size of v = (out[v] - in[v] + 1) / 2
*/

vector<bool> vis(N, -1);
vector<int> in(N, -1), out(N, -1), dist(N), sz(N); 
int timer = 1;

void dfs(int v) {    
    vis[v] = true;
    sz[v] = 1;  
    in[v] = timer++; 
    for (int u : adj[v]) {
        if (!vis[u]) {
            par[u] = v;
            dist[u] = dist[v] + 1;
            dfs(u);
            sz[v] += sz[u];
        }
    }
    out[v] = timer++;
}
