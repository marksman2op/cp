// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Chinese Remainder Theorem (CRT)
    - https://forthright48.com/chinese-remainder-theorem-part-1-coprime-moduli/
    - https://www.youtube.com/watch?v=H_Utja61nT4 by zeus_orz
    - modInv(x, y) = Modular inverse of x wrt y
      Modular inverse can be found only if GCD(x, y) = 1. 
    
    Given a system of equations:
    x % p(1) = k(1)
    x % p(2) = k(2)
    ...
    x % p(n) = k(n)

    CRT says then if p(1), p(2), .. p(n) are aint relatively prime with each other, 
    then we'int have only one solution modulo LCM(p(1), p(2), ..., p(n)) for the given system of equations. 
    
    Proof and solution creation: Garner's Algorithm
    Let's represent x as,
        x = x1 + x2 * p(1) + x3 * p(1) * p(2) + ... + xn * p(1) * p(2) * ... * p(n - 1)

    Now,
        x % p(1) = x(1) = k(1)
        x % p(2) = x(1) + x(2) * p(1) = k(2) => x(2) = (k(2) - k(1)) * modInv(p(1), p(2))
        x % p(3) = x(1) + x(2) * p(1) + x(3) * p(1) * p(2) = k(3) => x(3) = (k(3) - x(1) - x(2) * p(1)) * modInv(p(1), p(3)) * modInv(p(2), p(3))
    
    How to calculate each x(i)?
    x % p(i) = k(i)
    x(1) + x(2) * p(1) + x(3) * p(1) * p(2) + ... + x(i) * p(1) * p(2) * ... * p(i - 1) + 0 + 0 + ... + 0 = k(i) mod p(i)
    res + x(i) * p(1) * p(2) * ... * p(i - 1) = k(i) mod p(i)
    x(i) = (k(i) - res) * modInv(p(1), p(i)) * modInv(p(2), p(i)) * ... * modInv(p(i - 1), p(i))

    Time complexity: n * n * log2(p(max))

    Problems:
    - https://www.codechef.com/problems/GUESSPRM
    - https://codeforces.com/problemset/problem/919/E
*/  

int MOD = 1e9 + 7; 

int power(int x, int y, int m = MOD) {
    x %= m;
    int res = 1;
    while (y) {
        if (y & 1) 
            res = res * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return res;
}

int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int modInv(int a, int m) {
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        return -1;
    } else {
        x = (x % m + m) % m;
        return x;
    }
}

// CRT implementation for multiple equations
pair<int, int> CRT(vector<pair<int, int>> v) { // {p, k}
    int n = v.size();
    int m = 1; // m = p1 * p2 * ... * pn
    for (int i = 0; i < n; i++) {
        auto &[p, k] = v[i];
        k = (k % p + p) % p;
        m *= p;
    }   

    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = 1;
        for (int j = 0; j < i; j++) {
            t = t * v[j].first % m * modInv(v[j].first, v[i].first) % m;
        }
        res = (res + (t * ((v[i].second + m - res) % m) % m)) % m;
    }
    res = (res % m + m) % m;
    return {res, m}; 
}

// CRT implementation for 2 equations.
pair<int, int> CRT(int p1, int k1, int p2, int k2) { 
	// return (x, y) such that y = lcm(p1, p2), x % p1 = k1, x % p2 = k2
    int g, x, y;
    g = extended_euclidean(p1, p2, x, y);
    k1 = (k1 % p1 + p1) % p1;
    k2 = (k2 % p2 + p2) % p2;
    if (k1 % g != k2 % g) {
        return {-1, 0}; // Not possible
    }
    
    int l = p1 * (p2 / g);
    if (l < p1) {
        return {-2, 0}; // Overflow
    }

    int res = k1 + ((k2 - k1) % l + l) * x % l * (p1 / g);
    res = (res % l + l) % l;
    return {res, l};
}

void run_case() {
    int a, b, p, x;
    cin >> a >> b >> p >> x;

    ::MOD = p;
    int res = 0, q = 1;
    for (int i = 0; i < p - 1; i++) {
        int qi = b * modInv(q, p) % MOD; 
        // vector<pair<int, int>> v = {{p, qi}, {p - 1, i}};
        // auto pp = CRT(v);
        auto pp = CRT(p, qi, p - 1, i);
        // cout << pp.first << ' ' << pp.second << '\n';
        if (pp.first <= x) {
            res += 1 + (x - pp.first) / pp.second;
        }
        q = q * a % MOD;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++) {
        // cout << "Case #" << t << ": ";
        run_case();
    }
    
    return 0;
}