// Sky's the limit :)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std; 
#define int long long
  
// Ordered Set Tree 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

const int N = 2e5 + 5;

int n, a[N];

int cntInversion() {
    int cnt = 0;

    ordered_set st;
    st.insert(a[0]);
    for(int i = 1; i < n; i++) {
        st.insert(a[i]);
        int key = st.order_of_key(a[i] + 1);
        cnt += st.size() - key;
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
        
        cout << cntInversion() << '\n';
    }
    
    return 0;
}
