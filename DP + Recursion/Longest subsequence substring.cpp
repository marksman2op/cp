// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Longest subsequence of string s which is substring in string t
int LSS(string s, string t) {    // O(n * m)
    int n = s.size(), m = t.size();  
    int dp[105][105] = {}, ans = 0;
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
            if (s[j - 1] == t[i - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];  
            else
                dp[i][j] = dp[i][j - 1]; 
        } 
        ans = max(ans, dp[i][n]);
    }  
  
    return ans; 
} 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t = 1; 
    // cin >> t; 
    while (t--) {
        
    }
    
    return 0;
}

