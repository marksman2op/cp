//nCr in O(n)
const int mod = 1e9 + 7;
const int  N = 1e6 + 5;

int fac[N], inv[N];

void pre() { 
    fac[0] = inv[0] = inv[1] = 1;
    for(int i = 1; i < N; i++) 
        fac[i] = i * fac[i - 1] % mod;
    for(int i = 2; i < N; i++) 
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for(int i = 1; i < N; i++) 
        inv[i]= inv[i] * inv[i - 1] % mod;
}

int ncr(int n, int r) {
    if(r < 0 || r > n)
        return 0;
    return fac[n] * inv[r] % mod * inv[n - r] % mod;
}
