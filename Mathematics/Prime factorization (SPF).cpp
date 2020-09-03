// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Prime factorization using SPF Sieve O(log n)
const int N = 1e6 + 6;

int spf[N];

void pre() {
    for (int i = 0; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i)
                spf[j] = i;
        }
    } 
}

vector<int> factorize(int n) {
    vector<int> res; 
    while (n != 1) { 
        res.push_back(spf[n]); 
        n /= spf[n]; 
    } 
    return res; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        
    }
    
    return 0;
}

