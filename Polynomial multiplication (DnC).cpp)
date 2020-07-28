// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/* 
    Polynomial multiplication using DnC + Karatsuba’s algorithm
    
    The degree of the polynomial is n-1 where n is the number of coefficients.
    Multiplication mechanism:
    - The algorithm first breaks the polynomial into equal parts by halving the powers generating a polynomial which has low powers and other has high. 
        pLow = sum(pi * x^i), {0 <= i <= (n / 2) - 1}
        pHigh = sum(pi.x^i), {(n / 2) <= i <= (n - 1)}
        p = pHigh * x^(n / 2) + pLow
        Same is done to the q equation as well.
    - We break the polynomial until the number of coefficient is 1 and then we return the product of the only elements in the polynomials arrays.
    - The product, pq = pHigh * qHigh * x^n + (phigh * qLow + pLow * qHigh) * x^n/2 + pLow * qLow
    - The index of the array represents the power of the variable 'x' in the polynomial.
    - Now, if we see the middle term, we can represent that term in a different way which will reduce one multiplication operation and increase one addition operation. 
        pLow * qHigh + pHigh * qLow = [(pLow + phigh) * (qLow + qHigh)] - plow * qLow - pHigh * qHigh
    - So now we have to compute and perform only 3 multiplication operations.
    Time complexity = O(n ^ log(3)) = O(n ^ 1.59)
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        
    }
    
    return 0;
}

