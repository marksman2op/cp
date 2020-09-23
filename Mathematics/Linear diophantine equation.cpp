// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Linear Diophantine Equation
    - https://cp-algorithms.com/algebra/linear-diophantine-equation.html
    - A LDE (in two variables) is an equation of the general form: a * x + b * y = c where a, b, c are given integers, 
      and x, y are unknown integers.

    Special case
    - a = b = 0, if c = 0 we have infinitely many solutions, else no solutions.
    
    Finding any solution:
    - Find solution for abs(a) * x + abs(b) * y = 1
    - Multiply it by c / g, where g = gcd(a, b)
    - Adjust parity

    Finding all solutions:
    - Find any solution. Let it be (x0, y0)
    - Then all (x, y) such that x = x0 + k * (b / g), y = y0 - k * (a / g) are solution of given LDE

    Problems
    - https://codeforces.com/gym/100963 J

*/

const int INF = 1e10;

// Helper function for find_any_solution()
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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

// Helper function for find_all_solutions()
void shift_solution(int &x, int &y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

// This computes the number of solutions in given range and first and last valid x for solution.
// All (x, y) are solutions in given range where x = lx + k * (b / g) and y can be found from the equation.
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy, int &lx, int &rx) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    lx = max(lx1, lx2);
    rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {

    }
    
    return 0;
}

