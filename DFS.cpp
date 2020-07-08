// DFS
/*
    Applications: https://cp-algorithms.com/graph/depth-first-search.html
    SSSP on tree  
    Diameter of tree 
    Calculate subtree size of each node in tree
*/

// To check if v lies in subtree of u: in[u] < in[v] && out[u] > out[v]
// What’s subtree of node x? elements of discover from position in[x] to out[x].
// Subtree size of v = (out[v] - in[v] + 1) / 2

// DFS / In-Out time of nodes
vector<bool> vis(N, -1);
vector<int> in(N, -1), out(N, -1); 
int timer = 1;

void dfs(int v, int p = -1) {    
    vis[v] = true;
    par[v] = p;    
    in[v] = timer++; 
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u, v);
    }
    out[v] = timer++;
}
