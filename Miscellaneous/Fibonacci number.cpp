// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Time complexity: O(log(n) * log(log(n)))
const int M = 1e9 + 7; 
map<int, int> F;

int solve(int n) {
    if (F.count(n)) 
        return F[n];

    int k = n / 2;
    if (n % 2 == 0)
        return F[n] = (solve(k) * solve(k) + solve(k - 1) * solve(k - 1)) % M;
    else 
        return F[n] = (solve(k) * solve(k + 1) + solve(k - 1) * solve(k)) % M;
}

int fib(int n) {
    return (n == 0 ? 0 : solve(n - 1));
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        F[0] = F[1] = 1;
        int n;
        cin >> n;
        cout << fib(n) << '\n';
    }
    
    return 0;
}

