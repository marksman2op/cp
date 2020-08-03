const int N = 2e5 + 5;
const int INF = 1e10;

int n, m;
vector<int> adj[N];

// BFS
/* 
    Applications: https://cp-algorithms.com/graph/breadth-first-search.html
    Multisource BFS: Push all initial sources in queue.
    Single Source Shortest Path (SSSP) on simple unweighted graphs
    Check whether a graph is bipartite
    Diameter of tree: 
        1. Pick any vertex as source vertex.
        2. Find any most distant vertex from the source. Make this vertex new source.
        3. Distance between this source and the the most distant vertex from the source is diameter.
    
*/

// SSSP on graph
void bfs(int s) {
    queue<int> q;
    vector<bool> vis(N, 0);
    vector<int> dist(N, -1), par(N, -1);

    q.push(s);
    vis[s] = true;
    par[s] = -1;
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
                par[u] = v;
            }
        }
    }

    int d; // Restore and display the shortest path from the source to some vertex d 
    if (!vis[d]) {
        cout << "-1\n";
    } 
    else {
        vector<int> path;
        for (int v = d; v != -1; v = par[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        for (auto x: path)
            cout << x << ' ';
        cout << '\n';
    }
}
