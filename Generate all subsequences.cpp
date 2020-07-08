// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> a;

void generate(vector<int> b, int idx) {
    if(idx == n) {
        for(auto x : b)
            cout << x << ' ';
        cout << '\n';
    }
    else {
        generate(b, idx + 1);
        b.push_back(a[idx]);
        generate(b, idx + 1);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        a.resize(n);
        vector<int> b;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        generate(b, 0);
    }
    
    return 0;
}

