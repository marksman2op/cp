// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    MST using Prims Algorithm
    - The graph must be: Weighted, Undirected, Connected
    - By running Prim's algorithm separately for each connected component of the graph, it can be used to find the minimum spanning forest.
    
    - Time complexity
        - Dense graph: O(V * V)
        - Sparse graph: O(E log (V))
*/

// Sparse Graph
// const int N = 1005; 
// const int INF = 1e18; // Weight INF means there is no edge

// struct Edge {
//     int w = INF, to = -1;
//     bool operator<(Edge const& other) const {
//         return make_pair(w, to) < make_pair(other.w, other.to);
//     }
// };

// int n, m;
// vector<vector<Edge>> adj;

// void prim_sparse() {
//     int total_weight = 0;
//     vector<Edge> min_e(n);
//     min_e[0].w = 0;
//     set<Edge> q;
//     q.insert({0, 0});
//     vector<bool> selected(n, false);
//     for (int i = 0; i < n; ++i) {
//         if (q.empty()) {
//             cout << "No MST!" << endl;
//             exit(0);
//         }
// 
//         int v = q.begin()->to;
//         selected[v] = true;
//         total_weight += q.begin()->w;
//         q.erase(q.begin());

//         for (Edge e : adj[v]) {
//             if (!selected[e.to] && e.w < min_e[e.to].w) {
//                 q.erase({min_e[e.to].w, e.to});
//                 min_e[e.to] = {e.w, v};
//                 q.insert({e.w, e.to});
//             }
//         }
//     }
// 
//     cout << total_weight << '\n';
// }

// Dense Graph
int n, m;
vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 1e18; // weight INF means there is no edge

struct Edge {
    int w = INF, to = -1;
};

void prim_dense() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        // if (min_e[v].to != -1)
        //     cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    cout << total_weight << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n >> m;
        adj = vector<vector<int>> (n, vector<int> (n, INF));
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u][v] = adj[v][u] = w;
        }

        prim_dense();
        
        // Sparse
        // cin >> n >> m; 
        // adj = vector<vector<Edge>> (n, vector<Edge> ());
        // while (m--) {
        //     int u, v, w;
        //     cin >> u >> v >> w;
        //     u--, v--;
        //     adj[u].push_back({w, v});
        //     adj[v].push_back({w, u});
        // }

        // prim_sparse();
        
    }
    
    return 0;
}

