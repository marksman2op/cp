// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    In - Out DP on tree's:
    - https://www.youtube.com/watch?v=Xng1Od_v6Ug&list=PLfBJlB6T2eOsET4tlfcLs7oXR7kCyt1xc&index=2
    - https://blogarithms.github.io/articles/2019-10/inout-dp-tree

    Problem: Given a tree, for each node, output the distance to the node farthest from it.
    - We can get maximum height in subtree of v, or in the siblings of v, or outside the subtree of parent of v.
    - in[node] = max(in[node], 1 + in[child])
    - out[node] = max(2 + in[siblings], 1 + out[parent])
    - res[node] = max(in[node], out[node])

    Problems:
    - https://www.spoj.com/problems/ADASALES/
    - https://codeforces.com/problemset/problem/337/D
*/

const int N = 1e5 + 5;
int n, m;
vector<int> g[N], in(N), out(N);

void dfs_in(int v, int p) {
    in[v] = 0;
    for (auto &&u : g[v]) {
        if (u != p) {
            dfs_in(u, v);
            in[v] = max(in[v], 1 + in[u]);
        }
    }
}

void dfs_out(int v, int p) {
    // Find top 2 maximum values of in[v]
    int mx1 = -1, mx2 = -1;
    for (auto &&u : g[v]) {
            if (u != p) {
                if (in[u] >= mx1) {
                    mx2 = mx1; 
                    mx1 = in[u];
                }
                else if (in[u] > mx2) 
                    mx2 = in[u];
            }
    }

    for (auto &&u : g[v]) {
        if (u != p) {
            int use = (mx1 == in[u] ? mx2 : mx1);
            out[u] = max(1 + out[v], 2 + use);   
            dfs_out(u, v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs_in(1, -1);
        dfs_out(1, -1);

        for (int i = 1; i <= n; i++)
            cout << max(in[i], out[i]) << ' ';
        cout << '\n';
    }
    
    return 0;
}

