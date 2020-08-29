// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Rabin-Karp Algorithm:
    - Given two strings, a pattern s and a text t, determine all position where the pattern appears in the text.
    - Time complexity: O(|s| + |t|)
    - Concept: String hashing
    - Algorithm: Calculate the hash for the pattern s. Calculate hash values for all the prefixes of the text t. 
      Now, compare each substring of length |s| with the pattern.
*/

const int BASE = 31, MOD = 1e9 + 7, N = 1e6 + 5;

vector<int> pp(N); 

void pre() {
    pp[0] = 1; 
    for (int i = 1; i < N; i++) 
        pp[i] = pp[i - 1] * BASE % MOD;
}

vector<int> rabin_karp(const string &text, const string &pat) {
    int tn = text.size(), pn = pat.size();
    vector<int> pref(tn + 1, 0); 
    for (int i = 0; i < tn; i++)
        pref[i + 1] = (pref[i] + (text[i] - 'a' + 1) * pp[i]) % MOD; 
    int hs = 0; 
    for (int i = 0; i < pn; i++) 
        hs = (hs + (pat[i] - 'a' + 1) * pp[i]) % MOD; 

    vector<int> res;
    for (int i = 0; i + pn - 1 < tn; i++) { 
        int curr = (pref[i + pn] - pref[i] + MOD) % MOD; 
        if (curr == hs * pp[i] % MOD)
            res.push_back(i);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    pre();

    int T = 1; 
    cin >> T; 
    while (T--) {
        string text, pat;
        cin >> text >> pat;

        auto res = rabin_karp(text, pat);
        if (res.size() == 0)
            cout << "Not Found\n";
        else {
            cout << res.size() << '\n';
            for (auto &&x : res)
                cout << ++x << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}

