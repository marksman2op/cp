// Cycle detection 
vector<int> cycle;
int cycle_start, cycle_end;
bool undirected = true;

bool dfs_cycle(int v) {    // Find any back edge to detect cycle
    col[v] = 1;
    for (int u : adj[v]) {
        if (col[u] == 0) {
            par[u] = v;
            if (dfs_cycle(u))
                return true;
        } else if (col[u] == 1) {
            if(undirected && par[v] == u)    // Handles undirected graph
                continue;
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    col[v] = 2;
    return false;
}

void find_cycle() {    // Find any cycle and restore it
    col.assign(N, 0);
    par.assign(N, -1);
    cycle.clear();
    cycle_start = -1;

    for (int v = 1; v <= n; v++) {
        if (col[v] == 0 && dfs_cycle(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic\n";
    } else {
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = par[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}
