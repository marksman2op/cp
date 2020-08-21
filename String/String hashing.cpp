// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Rolling hash: https://codeforces.com/blog/entry/60445
    https://cp-algorithms.com/string/string-hashing.html
    Normally base = 31/53/137, MOD = 1e9 + 7, 1e9 + 9
    Base should also be strictly greater than the number of different values an individual element can be.
    Advice: Use randomiztion as given in dacin21's blog.
*/

// https://codeforces.com/gym/101628/problem/K

// Main Idea: Prefix hashing + binary search
// I have used double hashing to reduce the probability of collisions.
const int N = 5e5 + 5;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;

int n, q, p = 29, p1[N], p2[N];
string s[N];
unordered_map<int, set<int>> mp1, mpfull1, mp2, mpfull2;

void pre() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p1[i] = p1[i - 1] * p % M1;
        p2[i] = p2[i - 1] * p % M2;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    pre();

    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> s[i];

            int c1 = 0, c2 = 0;
            for (int j = 0; j < s[i].size(); j++) {
                int x = s[i][j] - 'a' + 1;
                c1 = (c1 + x * p1[j]) % M1;
                mp1[c1].insert(i);

                c2 = (c2 + x * p2[j]) % M2;
                mp2[c2].insert(i);
            }
            mpfull1[c1].insert(i);
            mpfull2[c2].insert(i);
        }

        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int idx;
                string t;
                cin >> idx >> t;
                // Replace the idx-th pos1ition in the array with the a string t
                
                int c1 = 0, c2 = 0;
                for (int j = 0; j < s[idx].size(); j++) {
                    int x = s[idx][j] - 'a' + 1;

                    c1 = (c1 + x * p1[j]) % M1;
                    mp1[c1].erase(idx);

                    c2 = (c2 + x * p2[j]) % M2;
                    mp2[c2].erase(idx);
                }
                mpfull1[c1].erase(idx);
                mpfull2[c2].erase(idx);

                c1 = c2 = 0;
                s[idx] = t;
                for (int j = 0; j < s[idx].size(); j++) {
                    int x = s[idx][j] - 'a' + 1;

                    c1 = (c1 + x * p1[j]) % M1;
                    mp1[c1].insert(idx);

                    c2 = (c2 + x * p2[j]) % M2;
                    mp2[c2].insert(idx);
                }
                mpfull1[c1].insert(idx);
                mpfull2[c2].insert(idx);
            }

            else if (type == 2) {
                int l, r;
                string t;               
                cin >> l >> r >> t;
                //  Check whether there is any string in sub-array [l, r] which is a prefix of t.
                
                // Hash prefixes of t and check if hash of s[i] == t[j:] 
                int c1 = 0, c2 = 0;
                bool ok = false;
                for (int j = 0; j < t.size(); j++) {
                    int x = t[j] - 'a' + 1;

                    c1 = (c1 + x * p1[j]) % M1;
                    c2 = (c2 + x * p2[j]) % M2;

                    if (mpfull1.find(c1) != mpfull1.end() && mpfull2.find(c2) != mpfull2.end()) {
                        int pos1 = *mpfull1[c1].lower_bound(l);
                        int pos2 = *mpfull2[c2].lower_bound(l);
                        if (pos1 >= l && pos1 <= r && pos2 >= l && pos2 <= r) {
                            ok = true;
                            break;
                        }
                    }
                }

                cout << (ok ? 'Y' : 'N') << '\n';
            }
            else {
                int l, r;
                string t;
                cin >> l >> r >> t;
                // Check whether t is prefix of any string in sub-array [l, r].
                
                int c1 = 0, c2 = 0;
                for (int j = 0; j < t.size(); j++) {
                    int x = t[j] - 'a' + 1;

                    c1 = (c1 + x * p1[j]) % M1;
                    c2 = (c2 + x * p2[j]) % M2;
                }

                bool ok = false;
                if (mp1.find(c1) != mp1.end() && mp2.find(c1) != mp2.end()) {
                    int pos1 = *mp1[c1].lower_bound(l);
                    int pos2 = *mp2[c2].lower_bound(l);
                    if (pos1 >= l && pos1 <= r && pos2 >= l && pos2 <= r) 
                        ok = true;
                }

                cout << (ok ? 'Y' : 'N') << '\n';
            }
        }
    }
    
    return 0;
}