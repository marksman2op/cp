// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

  
/* 
    MST with Krushkal's Algorithm 
    - The graph must be: Weighted, Undirected, Connected/Disconnected
    - Runs for disconnected graph without any modifications.
    
    - Steps:
        - Sort all the edges in non-decreasing order of their weight.
        - Pick the smallest edge. Check if it forms a cycle with the spanning-tree formed so far. If the cycle is not formed, include this edge. Else, discard it.
        - Repeat step#2 until there are (V - 1) edges in the spanning tree.
    - https://stackoverflow.com/questions/1195872/when-should-i-use-kruskal-as-opposed-to-prim-and-vice-versa
    - Time complexity: O(E log (V) + V + E) ≡ O(E log (V))
*/

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

const int N = 1e5 + 5;
int n, m;
vector<Edge> edges;
vector<int> rnk(N), par(N);

void init(int v) {
    par[v] = v;
    rnk[v] = 0;
}

int find(int v) {
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

void kruskal() {
    int cost = 0;
    vector<Edge> res;
    for (int i = 1; i <= n; i++)
        init(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            cost += e.w;
            res.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    cout << cost << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n >> m;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        kruskal();
    }
    
    return 0;
}

