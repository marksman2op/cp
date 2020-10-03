// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Sieve
    - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
    - https://codeforces.com/blog/entry/54090
    - https://codeforces.com/blog/entry/22229
    - https://codeforces.com/blog/entry/8989
*/

const int N = 1e6 + 5;

int spf[N], mu[N];

// Works in O (N * log (log (N)))
void pre() { 
    for (int i = 0; i < N; i++) {
        spf[i] = i;
        mu[i] = 1;
    }
    for (int i = 2; i < N; i++) {
        if (spf[i] == i) { // If i is prime
            for (int j = i; j < N; j += i) {
                spf[j] = i;
                mu[j] = -mu[j];
                if (j % (i * i) == 0)
                    mu[j] = 0;
            }
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

