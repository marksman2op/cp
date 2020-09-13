// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    https://www.geeksforgeeks.org/tiling-with-dominoes/
    Given a 3 x n board, find the number of ways to fill it with 2 x 1 dominoes.
*/

int solve(int n);

int helper(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return solve(n - 1) + helper(n - 2);
}

int solve(int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    return solve(n - 2) + 2 * helper(n - 1);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;

        cout << solve(n) << '\n';
    }
    
    return 0;
}

