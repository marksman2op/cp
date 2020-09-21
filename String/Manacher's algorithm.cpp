// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Manacher's Algorithm:
    - Finds all the pairs (i, j) such that substring s[i:j] is a palindrome.
    - For odd length palindromes
        - i is the index of centre letter
        - d1[i] = (l + 1) / 2, where l is the length of the palindrome centered at i
    - For even length palindromes
        -  i is the indec of latter of the two center's of palindrome
        - d2[i] = (l / 2), where l is the lenth of palindrome centered at i
    - If we have a sub-palindrome with length l with center at some position i, we also have sub-palindromes 
      with lengths (l - 2), (l - 4) etc. with centers at i.
    - Time complexity: O(n)

    Problems:
    - https://cses.fi/problemset/task/1111/
*/

vector<int> d1, d2;
void manacher(string s) {
    int n = s.size();
    d1 = d2 = vector<int>(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) 
            k++;
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) 
            k++;
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        string s;
        cin >> s;

        int n = s.size();
        manacher(s);
        // for (int i = 0; i < n; i++)
        //     cout << d1[i] << ' ';
        // cout << '\n';
        // for (int i = 0; i < n; i++)
        //     cout << d2[i] << ' ';
        // cout << '\n';

        int mx = 1, st = 0;
        for (int i = 0; i < n; i++) {
            if (2 * d1[i] - 1 > mx) {
                mx = 2 * d1[i] - 1;
                st = i - d1[i] + 1;
            }
            if (2 * d2[i] > mx) {
                mx = 2 * d2[i];
                st = i - d2[i];
            }
        }
        cout << s.substr(st, mx) << '\n';
    }
    
    return 0;
}

