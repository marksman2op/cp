// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// Longest increasing subsequence such that difference between any 2 consecutive elements is one
int LPIS(vector<int> &v) {    // O(n)
    int n = v.size();
    unordered_map<int, int> mp; 
    int dp[n] = {}, mx = 0;
    
    for (int i = 0; i < n; i++) { 
        if (mp.find(v[i] - 1) != mp.end()) { 
            int lastIndex = mp[v[i] - 1] - 1; 
            dp[i] = 1 + dp[lastIndex]; 
        } 
        else
            dp[i] = 1; 
  
        mp[v[i]] = i + 1;
        mx = max(mx, dp[i]);
    } 
  
    return mx; 
} 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t = 1; 
    // cin >> t; 
    while (t--) {
        
    }
    
    return 0;
}

