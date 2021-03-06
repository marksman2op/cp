// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Miller-Rabin primality test
using u64 = uint64_t;
using u128 = __uint128_t;
 
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

// If n <= 1e18, it is enough to test a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
bool MillerRabin(u64 n, int iter = 5) {  // Probabilistic in O(k * (log n) ^ 3)
    if (n < 2 || n % 6 % 4 != 1)         // Can be improved to O(k * (log n) ^ 2) by using FFT-based multiplication  
        return (n == 2 || n == 3);       // Deterministic variant works in O((log n) ^ 4) if FFT-based multiplication is used
 
    int s = __builtin_ctzll(n - 1);
    u64 d = n >> s;
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        
    }
    
    return 0;
}
