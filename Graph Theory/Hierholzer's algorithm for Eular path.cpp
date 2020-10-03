// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Problem: Find the Eulerian path in an undirected multigraph with loops in O(M).
    Euler path/walk/trail: Walk through the graph or multigraph which uses every edge exactly once.
    Euler circuit/tour/cycle: Euler path which starts and stops at the same vertex.
    - If a graph has an eulerian circuit, it also has an eulerian path.
    - How to check if euler circuit/path exists?
      Ignore the isolated vertices. Now if the graph has only one connected component, check for the following properties:
      - Undirected graph: 
        - Eulerian circuit: Every vertex has even degree.
        - Eulerian path: Either every vertex has even degree or exactly 2 vertices have odd degree.
      - Directed graph:
        - Eulerian circuit: Every vertex has equal indegree and outdegree.
        - Eulerian path: Either every vertex has equal indegree and outdegree OR (|V| - 2) vertices have equal indegree
          and outdegree and for one vertex indegree = outdegree + 1 and other one has indegree + 1 = outdegree.

    Hierholzer's algorithm for finding Eulerian circuit/path
    - Before using algorithm, first determine if there even exists an eulerian path/circuit.
    - If a graph does not have an eulerian circuit but has an eulerian path, we can still use Hierholzer's algorithm 
      to find the path by adding an extra edge to the graph and removing the edge after the circuit has been constructed.
    - Time complexity = O(|E|)

    Hamilton path (or Hamiltonian path): Path which visits every vertex exactly once.
    Hamilton cycles: Hamliton paths which start and stop at the same vertex.

    Problems:
    - https://codeforces.com/contest/508/problem/D
    - https://codeforces.com/contest/723/problem/E
    - https://codeforces.com/contest/500/problem/D
    - https://codeforces.com/contest/475/problem/B
*/

// Euler path/circuit in directed graph using Hierholzer's algorithm
const int N = 1e5 + 5;
int n, m;
int inDeg[N], outDeg[N];
vector<int> g[N], path;

int check_euler_path_directed() { // Return starting node if eular path exists, else return -1
    int eql = 0, in = 0, out = 0, st = -1;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == outDeg[i])
            eql++;
        else if (inDeg[i] == outDeg[i] + 1) 
            in++;
        else if (outDeg[i] == inDeg[i] + 1) {
            out++;
            st = i;
        }
    } 

    // cout << n << ' ' << eql << ' ' << in << ' ' << out << '\n';
    if (eql == n) // Euler cycle 
        return 1;
    else if (in == 1 && out == 1 && in + out + eql == n) // Euler path
        return st;
    else // None
        return -1;
}

void dfs_euler(int v) {
    while (outDeg[v] > 0) {
        outDeg[v]--;
        int u = g[v].back();
        g[v].pop_back();
        // cout << v << " -> " << u << '\n';
        dfs_euler(u);
    }
    path.push_back(v);
}

// // Euler path/circuit in undirected graph using Hierholzer's algorithm
// const int N = 1e5 + 5;
// int n, m;
// int deg[N];
// multiset<int> g[N];
// vector<int> path;

// int check_euler_path_undirected() { // Return starting node if eular path exists, else return -1
//     int even = 0, odd = 0, st = -1;
//     for (int i = 1; i <= n; i++) {
//         if (deg[i] % 2 == 0)
//             even++;
//         else if (deg[i] % 2 == 1) { 
//             odd++;
//             st = i;
//         }
//     } 

//     // cout << n << ' ' << even << ' ' << odd << '\n';
//     if (even == n) // Euler cycle 
//         return 1;
//     // else if (even == n - 2 && odd == 2) // Euler path
//     //     return st;
//     else // None
//         return -1;
// }

// void dfs_euler(int v) {
//     while (deg[v] > 0) {
//         int u = *g[v].begin();
//         deg[v]--;
//         deg[u]--;
//         g[v].erase(st.find(u));
//         g[u].erase(st.find(v));
//         // cout << v << " -> " << u << '\n';
//         dfs_euler(u);
//     }
//     path.push_back(v);
// }

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            // g[v].push_back(u);

            outDeg[u]++;
            inDeg[v]++;
        }

        int st = check_euler_path_directed();
        // cout << st << '\n';
        if (st == -1)
            cout << "-1\n";
        else {
            dfs_euler(st);
            if (path.size() != m + 1) // If graph is disconneceted
                cout << "-1\n";
            else {
                reverse(path.begin(), path.end());
                for (auto &&v : path)
                    cout << v << ' ';
                cout << '\n';
            }
        }
    }
    
    return 0;
}

