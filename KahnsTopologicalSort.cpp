// Kahn’s algorithm for Topological Sorting
vector<int> tsort;

bool kahns() {    // Returns true if topological sort exists, else false
    priority_queue<int> pq; // To find any topological sort
    // priority_queue<int, vector<int>, greater<int> > pq; // To find lexographically smallest topological sort
    
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) 
            pq.push(i);
    }

    while(!pq.empty()) {
        int v = pq.top();
        pq.pop();
        tsort.push_back(v);

        for(auto u : adj[v]) {
            in[u]--;
            if(in[u] == 0)
                pq.push(u);
        }
    }

    return tsort.size() == n;
}
