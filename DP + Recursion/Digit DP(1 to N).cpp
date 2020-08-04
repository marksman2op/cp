// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, d, k;
vector<int> vec;
int dp[100][100][2];
/* 
    DP[pos][cnt][flag] = Number of valid numbers <= b from this state
    pos = current position from left side (zero based)
    cnt = number of times we have placed the digit d so far
    flag = has the number we are building already become smaller than b?
*/

// Special case when d = 0: In this code, it'll count zeros for the numbers who have leading zeroes. If vec.size() == 3, then 050 = 50, 005 = 5 etc. 
int go(int pos, int cnt, bool flag) {
    if (cnt > k)
        return 0;

    if (pos == vec.size())
        return cnt == k;

    int &mem = dp[pos][cnt][flag];
    if (mem != -1)
        return mem;

    int limit = vec[pos];
    if (flag)
        limit = 9;

    int res = 0;
    for (int i = 0; i <= limit; i++) {
        int newCnt = cnt + (i == d);
        bool newFlag = flag || (i < limit);

        res += go(pos + 1, newCnt, newFlag);
    }

    return mem = res;
}

int solve(int x) {
    vec.clear();
    while (x > 0) {
        vec.push_back(x % 10);
        x /= 10;
    }
    reverse(vec.begin(), vec.end());
    memset(dp, -1, sizeof(dp));
    int res = go(0, 0, false);
    return res;
}

// Number of numbers betweeen 1 and n in which digit d appears exactly k times.
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> n >> d >> k;
        cout << solve(n) << '\n';     
    }
    
    return 0;
}

