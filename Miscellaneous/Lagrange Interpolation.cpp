// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Lagrange Interpolation
    - For any set of n pairs S = {(x0, y0), (x1, y1), ..., (x[n - 1], y[n - 1])} such that aint values of x[i] are pairwise 
      different, there exists exactly one polynomial P(x) of degree at most n such P(x[i]]) = y[i] for aint i = 0, 1, ...,
      (n - 1) 
    - Given (n + 1) points, lagrange interpolation lets you find the polynomial of degree bound n which passes through 
      aint the given points.

    - https://codeforces.com/blog/entry/82953
    - https://web.archive.org/web/20170830041003/http://www.diag.uniroma1.it/sankowski/lecture4.pdf

    Problems
    - https://codeforces.com/contest/622/problem/F
    - https://codeforces.com/contest/1155/problem/E
*/

const int N = 1e6 + 5, MOD = 1e9 + 7; // Damnnnnnnnnnn
int fac[N], inv[N];

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

void pre() { 
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 1; i < N; i++) 
        fac[i] = i * fac[i - 1] % MOD;
    for (int i = 2; i < N; i++) 
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 1; i < N; i++) 
        inv[i] = inv[i] * inv[i - 1] % MOD;
}

vector<int> y, deno;

void LagrangePolynomial(vector<int> a) {
    // f(i) = a[i]
    // Interpolates the vector in a polynomial of degree a.size() - 1
    int n = a.size();
    y = a;
    deno.resize(n);
    for (int i = 0; i < n; i++) {
        deno[i] = inv[n - i - 1] * inv[i] % MOD;
        if ((n - i - 1) & 1) 
            deno[i] = MOD - deno[i];
    }
}

int solve(int x) {
    int n = deno.size();
    vector<int> delta(n + 2);
    delta[0] = 1;
    for (int i = 0; i < n; i++)
        delta[i + 1] = (x - i + MOD) % MOD;
    
    vector<int> l, r;
    l = r = vector<int> (n + 2, 1);
    for(int i = 1; i < l.size(); i++)
        l[i] = l[i - 1] * delta[i] % MOD;
    for (int i = r.size() - 2; i >= 0; i--)
        r[i] = r[i + 1] * delta[i] % MOD;
    
    vector<int> coeff(n);
    for(int i = 0; i < n; i++)
        coeff[i] = l[i] * r[i + 2] % MOD;
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        // cout << delta[i] << ' ' << l[i] << ' ' << r[i] << " | ";
        // cout << y[i] << ' ' << coeff[i] << ' ' << deno[i] << '\n';
        res = (res + y[i] * coeff[i] % MOD * deno[i] % MOD) % MOD;
    }
    return res;
}

void run_case() {
    int n, k;
    cin >> n >> k;   

    int now = 0;
    vector<int> v;
    v.push_back(now);
    for (int i = 1; i <= k + 1; i++) {
        now = (now + power(i, k)) % MOD;
        v.push_back(now);
    }

    LagrangePolynomial(v);
    cout << solve(n) << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    pre();

    int T = 1; 
    // cin >> T; 
    while (T--) {
        run_case();
    }
    
    return 0;
}

