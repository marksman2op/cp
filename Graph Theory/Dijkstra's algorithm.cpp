// Dijkstra Algorithm: Non negative weighted, Directed/Undirected graph
vector<pair<int, int>> adjd[N];
// vector<int> par(N);
vector<int> dist(N);

void dijkstra(int s) {
    dist.assign(N, INF);
    par.assign(N, -1);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        int dv = pq.top().first;
        // one condtition is missing here, leads to higher time complexity
        pq.pop();

        for (auto edge : adjd[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                par[to] = v;
                pq.push({dist[to], to});
            }
        }
    }
}

void restore_path(int s, int t) {    // Shortest path from s to t
    vector<int> path;
    for (int v = t; v != s; v = par[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
}

