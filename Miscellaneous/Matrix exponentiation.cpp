// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html
const int N = 105;
const int MOD = 1000000007;

struct Matrix {
    int M[N][N] = {};
    Matrix operator *(Matrix &other) {
        Matrix res;
        memset(res.M, 0, sizeof res.M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    res.M[i][j] = (res.M[i][j] + (M[i][k] * other.M[k][j]));
                    res.M[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    Matrix power(int n) {
        Matrix res, a = *this;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                res.M[i][j] = (i == j);
        }
        while (n) {
            if (n & 1)
                res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        Matrix a;
        while (m--) {
            int u, v;
            cin >> u >> v;
            a.M[--u][--v] = 1;
        }

        a = a.power(k);
    }
    
    return 0;
}
