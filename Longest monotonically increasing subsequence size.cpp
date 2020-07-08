// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

 // Longest monotonically increasing subsequence size
int CeilIndex(vector<int>& v, int lo, int hi, int key) { 
    while (hi - lo > 1) { 
        int mid = lo + (hi - lo) / 2; 
        if (v[mid] >= key) 
            hi = mid; 
        else
            lo = mid; 
    } 
  
    return hi; 
} 
  
int LMIS(vector<int>& v) { // O(n logn)
    int n = v.size();
    if (n == 0) 
        return 0; 
  
    vector<int> tail(n, 0); 
    int length = 1;  
  
    tail[0] = v[0]; 
    for(int i = 1; i < v.size(); i++) { 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t = 1; 
    // cin >> t; 
    while (t--) {
        
    }
    
    return 0;
}

