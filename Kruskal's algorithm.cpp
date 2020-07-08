// MST - Kruskal with DSU -> Weighted Undirected graph, Will run on disconnected graph too
struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

vector<Edge> edges(N);
vector<int> rnk(N);

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
}
