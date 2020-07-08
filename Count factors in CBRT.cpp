// Sky's the limit :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

using u64 = uint64_t;
using u128 = __uint128_t;

const int N = 1e6 + 50;
int a[N];
vector<int> v;

void sieve() {
	memset(a, 1, sizeof(a));
    a[0] = a[1] = 0;
    for(int i = 2; i < N; i++) {
    	for(int j = i * i; j < N; j += i)
    		a[j] = 0;
    }

    for(int i = 2; i < N; i++) {
    	if(a[i])
    		v.push_back(i);
    }
}

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter = 5) { 
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

int count(int n) {
	int ans = 1;
	for(int i = 0; i < v.size(); i++) {
		int cnt = 1, p = v[i];
		while(n % p == 0) {
			n /= p;
			cnt++;
		}
		ans = ans * cnt;
	}

	int x = sqrtl(n);
	if (MillerRabin(n))
        ans = ans * 2; 
    else if (x * x == n && MillerRabin(x)) 
        ans = ans * 3; 
    else if (n != 1) 
        ans = ans * 4; 
    return ans; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t; 
    while(t--) {
       	int n;
        cin >> n;

        sieve();
        cout << count(n) << '\n';
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}

