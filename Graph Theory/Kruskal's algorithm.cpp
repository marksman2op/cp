// MST - Kruskal with DSU -> Weighted Undirected graph, Will run on disconnected graph too
// Time complexity: O(N * N + M log (M)) ≡ O(N * N log (N))
struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

const int N = 1e6 + 5;
vector<Edge> edges(N);
vector<int> rank(N), par(N);

void init(int v) {
    par[v] = v;
    rank[v] = 0;
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
        if (rank[a] < rank[b])
            swap(a, b);
        par[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
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
}
