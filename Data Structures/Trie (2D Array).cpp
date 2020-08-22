#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://codeforces.com/contest/706/problem/D
// https://codeforces.com/gym/101628/problem/K

const int N = 200005 * 35;

int trie[N][2];
int cnt[N];
int idx = 1; // Root node index = 0

void insert(int x) {
    int curr = 0;
    for (int i = 30; i >= 0; i--) {
        bool bit = (x & (1 << i));
        if (trie[curr][bit] == 0) { // Make new node
            curr = trie[curr][bit] = idx;
            cnt[idx]++;
            idx++;
        }
        else {
            curr = trie[curr][bit];
            cnt[curr]++;
        }
    }
}

void erase(int x){
    int curr = 0;
    for (int i = 30; i >= 0; i--) {
        bool bit = (x & (1 << i));
        if (trie[curr][bit] == 0)
            return;

        curr = trie[curr][bit];
        cnt[curr]--;
    }
}

int search(int x) {
    int res = x, curr = 0;
    for (int i = 30; i >= 0; i--) {
        bool bit = !(x & (1 << i));
        if (trie[curr][bit] == 0 || cnt[trie[curr][bit]] == 0) {
            if (trie[curr][bit ^ 1] == 0 || cnt[trie[curr][bit ^ 1]] == 0)
                break;
            curr = trie[curr][bit ^ 1];
        }
        else {
            res |= (1 << i);
            curr = trie[curr][bit];
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int q;
        cin >> q;
        while (q--) {
            char c;
            int x;
            cin >> c >> x;

            if (c == '+')
                insert(x);
            else if (c == '-')
                erase(x);
            else {
                int ans = search(x);
                cout << ans << '\n';
            }
        }
    }
    
    return 0;
}

