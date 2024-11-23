
struct Combinatorics {
    const int n, mod;
    vector<int> fact, invFact;

    Combinatorics(int n, int mod) : n(n), mod(mod), fact(n + 1), invFact(n + 1) {
        fact[0] = invFact[0] = invFact[1] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (long)i * fact[i - 1] % mod;
        }
        for (int i = 2; i <= n; i++) {
            invFact[i] = (long)invFact[mod % i] * (mod - mod / i) % mod;
        }
        for (int i = 2; i <= n; i++) {
            invFact[i] = (long)invFact[i] * invFact[i - 1] % mod;
        }
    }

    int choose(int n, int r) {
        if (r < 0 || r > n) {
            return 0;
        }
        return (long)fact[n] * invFact[r] % mod * invFact[n - r] % mod;
    }
};
