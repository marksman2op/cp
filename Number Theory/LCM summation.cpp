// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://www.spoj.com/problems/LCMSUM/
const int N = 1e6 + 5;

vector<int> phi(N), tot(N);

void PHI() {
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i)
            tot[j] += (i * phi[i]);
    }
}

// First Idea, Toient: ∑LCM(i, n) = ((∑(d * ETF(d)) + 1) * n) / 2 over d|n 
// Another idea: Mobius Inversion
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    PHI();

    int T = 1; 
    cin >> T; 
    while (T--) {
        int n;
        cin >> n;

        // https://forthright48.com/spoj-lcmsum-lcm-sum/
        int ans = (tot[n] + 1) * n / 2;
        cout << ans << '\n';
    }
    
    return 0;
}

