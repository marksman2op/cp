// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/
// https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/

/*
    S[n][k] = Number of partitions of n elements into k sets
    Recursive solution to find the solution for nth element:
        The previous n - 1 elements are divided into k partitions, i.e S(n - 1, k) ways. Put the
            nth element into one of the previous k partitions. So, ck * S(n - 1, k) ways.
        The previous n - 1 elements are divided into k - 1 partitions, i.e S(n - 1, k - 1) ways. Put the 
            nth element into a new partition (single element partition). So, S(n - 1, k - 1) ways.
        Finally, S(n, k) = k * S(n - 1, k) + S(n - 1, k - 1)

    n'th Bell number B[n] = Total number of ways to partition a Set 
    B[n] = Σ S[n][k] ∀ k ∈ [1, n]
*/

const int N = 1005;
const int mod = 1e9 + 7;

int S[N][N], B[N];

void pre() {
    for (int n = 1; n < N; n++) {
        for (int k = 1; k <= n; k++) { 
            if (k == 1) 
                S[n][k] = 1; 
            else
                S[n][k] = (k * S[n - 1][k] + S[n - 1][k - 1]) % mod;
        } 
    }

    for (int n = 1; n < N; n++) {
        int res = 0;
        for (int k = 1; k <= n; k++) 
            res += S[n][k];
        B[n] = res % mod;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    pre();

    int T = 1; 
    cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        cout << B[n] << '\n';
    }
    
    return 0;
}

