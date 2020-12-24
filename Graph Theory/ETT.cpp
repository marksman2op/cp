// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Euler Tour Technique/Tree Flattening:
    - ETT is a method of representing a rooted undirected tree in the form of a array.
    
    - https://codeforces.com/blog/entry/55374
    - https://codeforces.com/blog/entry/63020
    - https://codeforces.com/blog/entry/48417

    Problem:
    - https://www.codechef.com/problems/AVVST
    - https://codeforces.com/contest/877/problem/E
    - https://codeforces.com/problemset/problem/620/E
    - https://codeforces.com/contest/466/problem/E
*/

const int N = 1e5 + 5;
int n;
int tin[N], tout[N], timer = 1;
vector<int> g[N], tour;

void dfs(int v, int p) {
    tin[v] = timer++;
    tour.push_back(v);
    for (auto &&u : g[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = timer++;
    tour.push_back(v);
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

        dfs(1, -1);

        for (int i = 1; i <= n; i++)
            cout << tin[i] << ' ';
        cout << '\n';
        for (int i = 1; i <= n; i++)
            cout << tout[i] << ' ';
        cout << '\n';
        for (auto &&v : tour)
            cout << v << ' ';
        cout << '\n';
    }
    
    return 0;
}

