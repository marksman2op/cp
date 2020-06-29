// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
// Lexicographically smallest rotation
int LSR(string s) {    // Minimum number of rotations to make S the smallest lexicographical order string
    int n = s.size();
    int i = 0, j = 1;
    while(j < n) {
        int k = 0;
        while(k < n && s[(i + k) % n] == s[(j + k) % n])
            k++;
 
        if(s[(i + k) % n] <= s[(j + k) % n])
            j += (k + 1);
        else {
            i += (k + 1);
            if(i < j) {
                i = j;
                j++;
            }
            else
                j = i + 1;
        }
    }
    return i;
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        string s;
        cin >> s;
 
        cout << LSR(s) << '\n';
 
        
    }
    return 0;
} 