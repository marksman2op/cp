// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/* 
    Euler's totient function / Phi function 
    - ϕ(n) = Number of integers between 1 and n inclusive, which are coprime to n
    - https://cp-algorithms.com/algebra/phi-function.html
    - https://codeforces.com/blog/entry/7308
    - https://forthright48.com/gcd-sum-function/
    
    Properties
    - ϕ(p) = p − 1, for any prime p.
    - ϕ(p ^ k) = (p ^ k) − (p ^ (k − 1)), where p is a prime and k ≥ 1
    - ϕ(a * b) = ϕ(a) * ϕ(b) * g / ϕ(g), where g = gcd(a, b)
    - If, n = (p1 ^ k1) * (p2 ^ k2) * ... * (pk ^ kk)
      then, ϕ(n) = ϕ(p1 ^ k1) * ϕ (p2 ^ k2) * ... * ϕ(pk ^ kk)
                 = n * (1 - 1 / p1) * (1 - 1 / p2) * ... * (1 - 1 / pk)
    - For all d | n, ∑ ϕ(d) = n,  
    - If d | n, then there are ϕ(n / d) numbers for which gcd(m, n) = d, where m <= n

    Applications
    - a ^ n ≡ a ^ (n mod ϕ(m)) (mod m)

    Problems
    - https://www.spoj.com/problems/LCMSUM/
    - https://www.spoj.com/problems/GCDEX/
    - https://www.spoj.com/problems/GCDEX2/
    - https://www.spoj.com/problems/DCEPCA03/

*/

// Works in O(sqrt(n))
int phi_(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

const int N = 1e6 + 5;
vector<int> phi(N);

// O(n log log n)
void phi_sieve() {
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        
    }
    
    return 0;
}

