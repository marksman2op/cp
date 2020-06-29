// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://www.spoj.com/problems/INVCNT/
 
const int N = 2e5 + 5;
 
int n, a[N];
int bit[N];
 
// Point Update and Range Query
void update(int x, int val) {    // add "val" at index "x"
    while(x <= n) { 
        bit[x] += val;
        x += (x & (-x));
    }
}
 
int query(int x) {    // returns the sum of first "x" elements in given array a[]
    int sum = 0;      // Sum from l to r is query(r) - query(l - 1);
    while(x > 0) {
        sum += bit[x];
        x -= (x & (-x));
    }
    return sum;
}
 
int invCount(int a[], int n) {
    // Coordinate compression to handle negative and large values
    vector<int> v(a, a + n);
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        a[i] = pos + 1; 
    }
 
    fill(bit, bit + N, 0);
 
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        cnt += query(a[i] - 1);
        update(a[i], 1);
    }
 
    return cnt;
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
 
        cout << invCount(a, n) << '\n';
    }
    
    return 0;
} 
