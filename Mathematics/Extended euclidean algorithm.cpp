// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Extended Euclidean Algorithm
    - https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
    - https://codeforces.com/blog/entry/79167
*/

// Euclidean algorithm for computing the GCD
// This algorithm ends with a = g and b = 0
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

// Extended Euclidean Algorithm
// Returns gcd(a, b) and finds coefficients x and y such that, a * x + b * y = gcd(a, b)
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
       
    }
    
    return 0;
}

    