// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> PSE(vector<int> a) {
    stack<int> st;
    int n = a.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) { 
        while (!st.empty() && st.top() >= a[i]) 
            st.pop(); 
        if (st.empty()) 
            res[i] = -1; 
        else  
            res[i] = st.top();
        st.push(a[i]);
    } 
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        auto res = PSE(a);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}

