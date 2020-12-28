//nCr in O(n)
const int MOD = 1e9 + 7;
const int  N = 1e6 + 5;

int fac[N], ifac[N];

void pre() { 
    fac[0] = ifac[0] = ifac[1] = 1;
    for (int i = 1; i < N; i++) 
        fac[i] = i * fac[i - 1] % MOD;
    for (int i = 2; i < N; i++) 
        ifac[i] = ifac[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 1; i < N; i++) 
        ifac[i]= ifac[i] * ifac[i - 1] % MOD;
}

int choose(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    return fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
}
