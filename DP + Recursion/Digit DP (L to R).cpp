#include <bits/stdc++.h>
using namespace std;
#define int long long

string a, b;
int mx;
vector<int> va, vb;
int dp[100][2][2][2];
 
int go(int pos, int rmx, int rmn, bool flag) {
    if(pos == mx) 
        return flag;
 
    int &mem = dp[pos][rmx][rmn][flag];
    if(mem != -1) 
        return mem;
 
    int ans = 0;
    int mx = rmx ? 9 : vb[pos];
    int mn = rmn ? 0 : va[pos];
    for(int i = mn; i <= mx; i++) {
        int newFlag = flag || (i > 0);
        int mul = newFlag ? i : 1;

        ans = max(ans, mul * go(pos + 1, rmx || i < mx, rmn || i > mn, newFlag));
    }

    return mem = ans;
}
 
int backtrack(int pos, int rmx, int rmn, bool flag) {
    if(pos == mx) 
        return flag;
    
    int &mem = dp[pos][rmx][rmn][flag];
 
    int mx = rmx ? 9 : vb[pos];
    int mn = rmn ? 0 : va[pos];
    for(int i = mn; i <= mx; i++) {
        int newFlag = flag || (i > 0);
        int mul = newFlag ? i : 1;

        if(mem == mul * go(pos + 1, rmx || i < mx, rmn || i > mn, newFlag)) {
            if(newFlag) 
                cout << i;

            backtrack(pos + 1, rmx || i < mx, rmn || i > mn, newFlag);
            break;
        }
    }
    
    return mem;
}
 
void solve(string a, string b) {
    va.clear();
    vb.clear();
    mx = max(a.size(), b.size());
    a.insert(0, (mx - a.size()), '0');
    b.insert(0, (mx - b.size()), '0');
    for(int i = 0; i < mx; i++) {
        va.push_back(a[i] - '0');
        vb.push_back(b[i] - '0');
    }
     
    memset(dp, -1, sizeof(dp));
    int ans = go(0, 0, 0, false);
    backtrack(0, 0, 0, 0);
} 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> a >> b;

        solve(a, b);
    }
    
    return 0;
}