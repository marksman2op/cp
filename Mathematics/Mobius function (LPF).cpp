// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long


/*
    Mobius Function:
    - https://math.berkeley.edu/~stankova/MathCircle/Multiplicative.pdf
    - https://discuss.codechef.com/t/a-dance-with-mobius-function/11315
    - https://codeforces.com/blog/entry/53925
    
    For every positive integer n, 
        μ(n) = 1 if n is a square-free positive integer with an even number of prime factors.
        μ(n) = −1 if n is a square-free positive integer with an odd number of prime factors.
        μ(n) = 0 if n has a squared prime factor.
*/

const int N = 1e6 + 5;

int lpf[N], mobius[N];
bool prime[N];
vector<int> primes;

// Works in O(N)
void pre() {
    for (int i = 2; i < N; i++) {
        if (!lpf[i]) {
            lpf[i] = i;
            prime[i] = true;
            primes.push_back(i);
        }

        for (int j = 0; j < primes.size() && primes[j] <= lpf[i] && i * primes[j] < N; j++) 
            lpf[i * primes[j]] = primes[j];
    }

    // Process mobius function
    for (int i = 0; i < N; i++)
        mobius[i] = 1;
    for (int i = 2; i < N; i++) 
        mobius[i] = (i / lpf[i] % lpf[i] ? -mobius[i / lpf[i]] : 0);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {

    }
    
    return 0;
}

